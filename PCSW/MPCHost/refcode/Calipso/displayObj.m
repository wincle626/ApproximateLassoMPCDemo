%% *reformatObj*
% convert output
%% *prerequisites*
% create the calipso.mat file
% wobj - has, for each component of the satellite: 
%   fv - facet vertices (triangles each defined by 3 indices to vertices)
%  fvn - facet vertex normals (each vertex has a normal vector)
% Vertex - the array of three Vertex [x,y,z] values
% VertexNormal - the array of normals [x,y,z]
%% *display*
% Although the data can be displayed with vertices, vertex normals, and
% assigning the material value to the vertices, this implmentation
% assigns the Kd color of the material file to the face color, and the
% material properties of Ka, Kd, and Ks are taken as scalars as implemented
% for phong shading in matlab.  The specular strength and phong
% reflectance-related coefficients are found in the material file
% associated with the object facets/vertices.
%% *history*
% WHEN      WHO    WHY/WHAT
% 20190406  mnoah  models for astronomy education
%% *start*
%%
clc
close all
clear all

load('calipso.mat','wobj','Vertex');
ncomp = length(wobj);

figure();
shading interp
hold on;

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
axis equal
view(35,50)

% up to 8 lights
l = light('Position',[-0.4  0.2  0.9],'Style','infinite');
l = light('Position',[ 0.4 -0.2  0.9],'Style','infinite');
l = light('Position',[-0.4  0.2 -0.9],'Style','infinite');
l = light('Position',[ 0.4 -0.2 -0.9],'Style','infinite');

lightangle(45,70)
camlight('headlight')

return

