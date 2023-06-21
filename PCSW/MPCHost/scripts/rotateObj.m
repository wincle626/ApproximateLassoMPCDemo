function rotateObj(ncomp, s, ...
    h17, h18, h19, yaw, pitch, roll)
%     h11, h12, h13, ...
%     h14, h15, h16, ...

%     load('calipso.mat','wobj','Vertex');
%     ncomp = length(wobj);
%     shading interp
% 
%     for icomp = 1:ncomp
%         s(icomp) = trisurf(wobj(icomp).fv,Vertex(:,1),Vertex(:,2),Vertex(:,3));
%         material(s(icomp), ...
%             [wobj(icomp).Ka mean(wobj(icomp).Color(:)) wobj(icomp).Ks wobj(icomp).Ns 1]);
%         s(icomp).EdgeColor = 'none';
%         s(icomp).BackFaceLighting = 'lit';
%         s(icomp).FaceLighting = 'phong';
%         s(icomp).FaceColor = wobj(icomp).Color;
%         s(icomp).AmbientStrength = 0.6;
%         hold on;
%     end
%     
%     % up to 8 lights
%     l = light('Position',[-0.4  0.2  0.9],'Style','infinite');
%     l = light('Position',[ 0.4 -0.2  0.9],'Style','infinite');
%     l = light('Position',[-0.4  0.2 -0.9],'Style','infinite');
%     l = light('Position',[ 0.4 -0.2 -0.9],'Style','infinite');
%     
%     axis equal
%     axis off
%     view([30, 10])
%     lightangle(45,70)
%     camlight('headlight')
%     material('dull');
% 
%     R = 5000;
%     phi = (-pi:pi/36:pi)';
%     D1 = [sin(phi) cos(phi) zeros(size(phi))];
%     hold on;
%     ax = gca;
%     h11 = plot3(R * D1(:,1), R * D1(:,2), R * D1(:,3), ...
%         '-', 'linewidth', 2, ...
%         'Color', 'r', 'tag', 'Zplane', 'Parent', ax);
%     h12 = plot3(R * D1(:,2), R * D1(:,3), R * D1(:,1), ...
%         '-', 'linewidth', 2, ...
%         'Color', [0, 0.8, 0], 'tag', 'Yplane', 'Parent', ax);
%     h13 = plot3(R * D1(:,3), R * D1(:,1), R * D1(:,2), ...
%         '-', 'linewidth', 2, ...
%         'Color', 'b', 'tag', 'Xplane', 'Parent', ax);
% 
%     S = 0.98;
%     phi = -180:10:180;
%     phi = phi*pi / 180;
%     D1 = [sin(phi); cos(phi); zeros(size(phi))];
%     h14 = plot3([S * R * D1(1, :); R * D1(1, :)], ...
%         [S * R * D1(2, :); R * D1(2, :)], ...
%         [S * R * D1(3, :); R * D1(3, :)], ...
%         '-', 'linewidth', 3, ...
%         'Color', 'r', 'tag', 'Zplane', 'Parent', ax);
%     h15 = plot3([S * R * D1(2, :); R * D1(2, :)], ...
%         [S * R * D1(3, :); R * D1(3, :)], ...
%         [S * R * D1(1, :); R * D1(1, :)], ...
%         '-', 'linewidth', 3, ...
%         'Color', [0 0.8 0], 'tag', 'Yplane', 'Parent', ax);
%     h16 = plot3([S * R * D1(3, :); R * D1(3, :)], ...
%         [S * R * D1(1, :); R * D1(1, :)], ...
%         [S * R * D1(2, :); R * D1(2, :)], ...
%         '-', 'linewidth', 3, ...
%         'Color', 'b', 'tag', 'Xplane', 'Parent', ax);
% 
%     h17 = plot3([0, 0], [ 0, 0], [-R, R], ...
%         '-', 'linewidth', 3, ...
%         'tag', 'heading_line', 'parent', ax, 'color','b');
%     h18 = plot3([-R, R], [ 0, 0], [0 ,0], ...
%         '-', 'linewidth', 3, ...
%         'tag',   'pitch_line', 'parent', ax, 'color',[0 0.8 0]);
%     h19 = plot3([ 0, 0], [-R, R], [0, 0], ...
%         '-', 'linewidth', 3, ...
%         'tag',    'roll_line', 'parent', ax, 'color','r');
% 
%     hold off;

    for icomp = 1:ncomp
        rotate(s, [1 0 0], yaw);
        rotate(s, [0 1 0], pitch);
        rotate(s, [0 0 1], roll);
%         rotate(h11, [1 0 0], yaw);
%         rotate(h11, [0 1 0], pitch);
%         rotate(h11, [0 0 1], roll);
%         rotate(h12, [1 0 0], yaw);
%         rotate(h12, [0 1 0], pitch);
%         rotate(h12, [0 0 1], roll);
%         rotate(h13, [1 0 0], yaw);
%         rotate(h13, [0 1 0], pitch);
%         rotate(h13, [0 0 1], roll);
%         rotate(h14, [1 0 0], yaw);
%         rotate(h14, [0 1 0], pitch);
%         rotate(h14, [0 0 1], roll);
%         rotate(h15, [1 0 0], yaw);
%         rotate(h15, [0 1 0], pitch);
%         rotate(h15, [0 0 1], roll);
%         rotate(h16, [1 0 0], yaw);
%         rotate(h16, [0 1 0], pitch);
%         rotate(h16, [0 0 1], roll);
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
end
