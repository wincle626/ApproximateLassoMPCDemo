% function rotateObj(yaw, pitch, roll)
    clear;
    clc;
    close all;

%     al = yaw;
%     be = pitch;
%     ga = roll;
% 
%     R = ...
%         [cos(al)*cos(be), cos(al)*sin(be)*sin(ga) - sin(al)*cos(ga), cos(al)*sin(be)*cos(ga) + sin(al)*sin(ga); ... 
%         sin(al)*cos(be), sin(al)*sin(be)*sin(ga) + cos(al)*cos(ga), sin(al)*sin(be)*cos(ga) - cos(al)*sin(ga); ...
%         -sin(be), cos(be)*sin(ga), cos(be)*cos(ga) ];

    load('calipso.mat','wobj','Vertex');
    ncomp = length(wobj);
%     Vertex = Vertex * R;
    
    h2 = figure(2); clf(h2);
    x1=100;
    y1=800;
    width1=640;
    height1=600;
    set(gcf,'position',[x1,y1,width1,height1])
    shading interp

    for icomp = 1:ncomp
        s(icomp) = trisurf(wobj(icomp).fv,Vertex(:,1),Vertex(:,2),Vertex(:,3));
        material(s(icomp), ...
            [wobj(icomp).Ka mean(wobj(icomp).Color(:)) wobj(icomp).Ks wobj(icomp).Ns 1]);
        s(icomp).EdgeColor = 'none';
        s(icomp).BackFaceLighting = 'lit';
        s(icomp).FaceLighting = 'phong';
        s(icomp).FaceColor = wobj(icomp).Color;
        s(icomp).AmbientStrength = 0.6;
        hold on;
    end
    
    % up to 8 lights
    l = light('Position',[-0.4  0.2  0.9],'Style','infinite');
    l = light('Position',[ 0.4 -0.2  0.9],'Style','infinite');
    l = light('Position',[-0.4  0.2 -0.9],'Style','infinite');
    l = light('Position',[ 0.4 -0.2 -0.9],'Style','infinite');
    
    axis equal
    axis off
    view([30, 10])
    lightangle(45,70)
    camlight('headlight')
    material('dull');

    R = 5000;
    phi = (-pi:pi/36:pi)';
    D1 = [sin(phi) cos(phi) zeros(size(phi))];
    hold on;
    ax = gca;
    h11 = plot3(R * D1(:,1), R * D1(:,2), R * D1(:,3), ...
        '-', 'linewidth', 2, ...
        'Color', 'r', 'tag', 'Zplane', 'Parent', ax);
    h12 = plot3(R * D1(:,2), R * D1(:,3), R * D1(:,1), ...
        '-', 'linewidth', 2, ...
        'Color', [0, 0.8, 0], 'tag', 'Yplane', 'Parent', ax);
    h13 = plot3(R * D1(:,3), R * D1(:,1), R * D1(:,2), ...
        '-', 'linewidth', 2, ...
        'Color', 'b', 'tag', 'Xplane', 'Parent', ax);

    S = 0.98;
    phi = -180:10:180;
    phi = phi*pi / 180;
    D1 = [sin(phi); cos(phi); zeros(size(phi))];
    h14 = plot3([S * R * D1(1, :); R * D1(1, :)], ...
        [S * R * D1(2, :); R * D1(2, :)], ...
        [S * R * D1(3, :); R * D1(3, :)], ...
        '-', 'linewidth', 3, ...
        'Color', 'r', 'tag', 'Zplane', 'Parent', ax);
    h15 = plot3([S * R * D1(2, :); R * D1(2, :)], ...
        [S * R * D1(3, :); R * D1(3, :)], ...
        [S * R * D1(1, :); R * D1(1, :)], ...
        '-', 'linewidth', 3, ...
        'Color', [0 0.8 0], 'tag', 'Yplane', 'Parent', ax);
    h16 = plot3([S * R * D1(3, :); R * D1(3, :)], ...
        [S * R * D1(1, :); R * D1(1, :)], ...
        [S * R * D1(2, :); R * D1(2, :)], ...
        '-', 'linewidth', 3, ...
        'Color', 'b', 'tag', 'Xplane', 'Parent', ax);

    h17 = plot3([0, 0], [ 0, 0], [-R, R], ...
        '-', 'linewidth', 3, ...
        'tag', 'heading_line', 'parent', ax, 'color','b');
    h18 = plot3([-R, R], [ 0, 0], [0 ,0], ...
        '-', 'linewidth', 3, ...
        'tag',   'pitch_line', 'parent', ax, 'color',[0 0.8 0]);
    h19 = plot3([ 0, 0], [-R, R], [0, 0], ...
        '-', 'linewidth', 3, ...
        'tag',    'roll_line', 'parent', ax, 'color','r');

    hold off;

    yaw = 0.5;
    pitch = 0.2;
    roll = 0.3;

    for i = 1:20
        for icomp = 1:ncomp
            rotate(s, [1 0 0], yaw);
            rotate(s, [0 1 0], pitch);
            rotate(s, [0 0 1], roll);
            rotate(h11, [1 0 0], yaw);
            rotate(h11, [0 1 0], pitch);
            rotate(h11, [0 0 1], roll);
            rotate(h12, [1 0 0], yaw);
            rotate(h12, [0 1 0], pitch);
            rotate(h12, [0 0 1], roll);
            rotate(h13, [1 0 0], yaw);
            rotate(h13, [0 1 0], pitch);
            rotate(h13, [0 0 1], roll);
            rotate(h14, [1 0 0], yaw);
            rotate(h14, [0 1 0], pitch);
            rotate(h14, [0 0 1], roll);
            rotate(h15, [1 0 0], yaw);
            rotate(h15, [0 1 0], pitch);
            rotate(h15, [0 0 1], roll);
            rotate(h16, [1 0 0], yaw);
            rotate(h16, [0 1 0], pitch);
            rotate(h16, [0 0 1], roll);
            rotate(h17, [1 0 0], yaw);
            rotate(h17, [0 1 0], pitch);
            rotate(h17, [0 0 1], roll);
            rotate(h18, [1 0 0], yaw);
            rotate(h18, [0 1 0], pitch);
            rotate(h18, [0 0 1], roll);
            rotate(h19, [1 0 0], yaw);
            rotate(h19, [0 1 0], pitch);
            rotate(h19, [0 0 1], roll);
        end
        yaw = yaw + 0.1 * pi / 180;
        pitch = pitch + 0.1 * pi / 180;
        roll = roll + 0.1 * pi / 180;
        pause(0.5)
    end
    
% end
