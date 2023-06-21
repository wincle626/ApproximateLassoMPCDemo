%% Constrained QP MPC problem:
% min sum_1^N ||x(k)^T*Q(k)*x(k)+u(k)^T*R(k)*u(k)||_2^2+lamda*||u(k)||_1
% s.t. x(k+1) = A*x(k) + B*u(k)
N = 10;
Ts = 0.1;
w0 = 1;
i11 = 4.250;
i22 = 4.337;
i33 = 3.664;
Iw = 4.0e-5;
k = i22 - Iw;
kx = (i22 - i33)/i11;
ky = (i11 - i33)/i22;
kz = (i22 - i11)/i33;

% example of a simple LTI system
% Ac = [  0               0               (1-kx)*w0           0              -8*kx*w0^2           0                   0;          ...
%         0               0               0                   0               0                  -6*ky*i22*w0^2/k     0;          ...
%         (kz -1)*w0      0               0                   0               0                   0                  -2*kz*w0^2;  ...
%         0               0               0                   0               0                  -6*ky*i22*w0^2/k     0;          ...
%         0.5             0               0                   0               0                   0                   0;          ...
%         0               0.5             0                   0               0                   0                   0;          ...
%         0               0               0.5                 0               0                   0                   0];    
% Bc = [  1/i11           0               0                   0;          ...
%         0               1/k             0                   -1/k;       ... 
%         0               0               1/i33               0;          ...
%         0               -1/k            0                   i22/k*Iw;   ...
%         0               0               0                   0;          ...
%         0               0               0                   0;          ...
%         0               0               0                   0];
Ac = [  0               0               (1-kx)*w0           0              -8*kx*w0^2           0                   0;          ...
        0               0               0                   0               0                  -6*ky*i22*w0^2/k     0;          ...
        (kz -1)*w0      0               0                   0               0                   0                  -2*kz*w0^2;  ...
        0               0               0                   0               0                  6*ky*i22*w0^2/k     0;          ...
        0.5             0               0                   0               0                   0                   0;          ...
        0               0.5             0                   0               0                   0                   0;          ...
        0               0               0.5                 0               0                   0                   0];    
Bc = [  1/i11           0               0                   0;          ...
        0               1/k             0                   -1/k;       ... 
        0               0               1/i33               0;          ...
        0               -1/k            0                   i22/(k*Iw);   ...
        0               0               0                   0;          ...
        0               0               0                   0;          ...
        0               0               0                   0];
Cc = eye(7); 
Dc = zeros(7,4);
sys = ss(Ac,Bc,Cc,Dc,Ts);
[A,B,C,D] = ssdata(sys);
% A = Ac; B = Bc; C = Cc; D = Dc;
m = size(A,1);            % Dimension of state
n = size(B,2);            % Dimension of input control
l = size(C,1);            % Dimension of output
Q  = diag([500,500,500,1.0e-7,1,1,1]);
R  = diag([200,200,200,1]);
% x0 = 0.1*ones(7,1);     % compulsory   
% x0 = [0;0;0;1;0;0;0];
% x0 = [-0.05;0.15;-0.08;300;-25;60;90];  % case I
x0 = [0.0035;0.0052;0.0035;0.5;0.1;0.1;0.1]; % case II
umax =  [   0.0484;    0.0484;     0.0398;      0.0020   ];           
umin = -umax;
xmax = [1; 1; 1; 800; 1; 1; 1];
% xmax(4) = 527;  
xmin = -xmax;
% ymax =  [   1;          1;         1;           800;        1;      1;      1   ];
% ymin = -[   1;          1;         1;           800;        1;      1;      1   ];
ymax =  [   1;          1;         1;           527;        1;      1;      1   ];
ymin = -[   1;          1;         1;           527;        1;      1;      1   ];
T = 25;
constraint = false;

%% QP to Lasso convert
PSI = zeros(size(A,1)*N,size(A,2));
for i=1:N
    PSI((i-1)*size(A,1)+1:i*size(A,1),1:size(A,2)) = A^i;
end 
THETA = zeros(size(A,1)*N,size(B,2)*N);
for i=1:N
    for j=1:i
        THETA((i-1)*size(A,1)+1:i*size(A,1), ...
              (j-1)*size(B,2)+1:j*size(B,2)) = A^(i-j)*B;
    end
end
K_lqr = lqry(sys,Q,R);
Q_hat = zeros(size(Q,1)*N, size(Q,2)*N);
R_hat = zeros(size(R,1)*N, size(R,2)*N);
for i=1:N
    Q_hat((i-1)*size(Q,1)+1:i*size(Q,1), ...
          (i-1)*size(Q,2)+1:i*size(Q,2)) = Q;
    R_hat((i-1)*size(R,1)+1:i*size(R,1), ...
          (i-1)*size(R,2)+1:i*size(R,2)) = R;
end
Q_bar = dlyap((A-B*K_lqr)', Q+K_lqr'*R*K_lqr);
Q_hat((i-1)*m+1:i*m,(i-1)*m+1:i*m) = Q_bar;
H = THETA'*Q_hat*THETA + R_hat;
F = THETA'*Q_hat*PSI;

% %% Matlab QP Simulation
% K = H\F;
% K_mpc = K(1,:);
% x = x0;
% t_constrained = 0:40;
% for ct = t_constrained
%     uLQR(:,ct+1) = -K_lqr*x;
%     if constraint
%         uLQR(:,ct+1) = max([umin min([umax uLQR(:,ct+1)],[],2)],[],2);
%     end
% %     uLQR(:,ct+1) = max([-ones(4,1) min([ones(4,1) uLQR(:,ct+1)],[],2)],[],2);
%     x = A*x+B*uLQR(:,ct+1);
%     yLQR(:,ct+1) = C*x;
%     if constraint
%         yLQR(:,ct+1) = max([ymin min([ymax yLQR(:,ct+1)],[],2)],[],2);
%     end
% end
% h=figure;
% plot(t_constrained,uLQR(1,:),'linewidth',2);
% hold on;
% plot(t_constrained,uLQR(2,:),'linewidth',2);
% plot(t_constrained,uLQR(3,:),'linewidth',2);
% plot(t_constrained,uLQR(4,:),'linewidth',2);
% legend('$\tau_1$','$\tau_2$','$\tau_3$','$\tau_\omega$', ...
%        'Interpreter','latex');
%% Matlab MPC Toolbox Sovler
% sys = ss(Ac,Bc,Cc,Dc, Ts);
% [K,Qp] = lqry(sys,Q,R);
% L = chol(Qp);
% newsys = sys;
% set(newsys,'C',[C;L],'D',[D;zeros(size(D,1),size(D,2))]);
% % newsys = setmpcsignals(newsys,'MO',[1 2],'UO',[3 4]);
% p = 10;
% m = p;
% MPCobj = mpc(newsys,Ts,p,m);
% ywt = sqrt(diag(Q))';
% uwt = sqrt(diag(R))';
% MPCobj.Weights.OV = [sqrt(diag(Q))' zeros(1,size(D,1))];
% MPCobj.Weights.MV = sqrt(R);
% Y = struct('Weight',[zeros(1,size(D,1)) ones(1,size(D,1))]);
% U = struct('Weight',uwt);
% setterminal(MPCobj,Y,U);
% MPCobj.MV(1).Min = umin(1);
% MPCobj.MV(2).Min = umin(2);
% for i=1:length(umin')
%     MPCobj.MV(i).Min = umin(i);
%     MPCobj.MV(i).Max = umax(i);
% end
% for i=1:length(ymin')
%     MPCobj.OV(i).Min = ymin(i);
%     MPCobj.OV(i).Max = ymax(i);
% end
% T = 20;
% r = [x0' zeros(1,7)];
% review(MPCobj)
% sim(MPCobj,T,r)