%% *reformatObj*
% convert output
%% *prerequisites*
% download the NASA 3D models
% https://nasa3d.arc.nasa.gov/detail/calipso
% and any other one you want
%
% download and install FBX Converter from Autodesk (2013)
% https://www.autodesk.com/developer-network/platform-technologies/fbx-converter-archives
% use this to convert the NASA Calipso fbx to an .obj (wavefront)
% format.
%% *history*
% WHEN      WHO    WHY/WHAT
% 20190406  mnoah  models for astronomy education
%% *start*
%%
clc
close all
clear all

%% read the materials file into a matlab table
fileMat = 'calipso.mat';
if (~exist(fileMat,'file'))
    reformatMtl;
    load(fileMat,'materials')
else
    load(fileMat,'materials')
    if (~exist('materials','var'))
        reformatMtl;
        load(fileMat,'materials')
    end
end

fileObj = 'calipso_v016_trip.obj';
fileMat = 'calipso.mat';

%% read the data file
str = fileread(fileObj);
lines = regexp(str, '\r\n|\r|\n', 'split');
lines = lines';

%% parse into faces, vectors, normals
idxStartOfComponent = find(contains(lines,'g '));
idxFacet = find(contains(lines,'f '));
idxVertexNormal = find(contains(lines,'vn '));
idxVertex = find(contains(lines,'v '));
idxMaterialDefinition = find(contains(lines,'usemtl'));
nComponents = length(idxStartOfComponent);

%% get arrays of facets, vectors, normals
lineTmp = lines(idxFacet);
facetIdxV = zeros(length(lineTmp),3);
facetIdxVN = zeros(length(lineTmp),3);
lineTmp = strrep(strrep(lineTmp,'f ',''),'//',' ');
for ifacet = 1:length(lineTmp)
    ix = sscanf(lineTmp{ifacet},'%f %f %f %f %f %f');
    facetIdxV(ifacet,:) = [ix(1) ix(3) ix(5)];  % idx of vertex
    facetIdxVN(ifacet,:) = [ix(2) ix(4) ix(6)]; % idx of vertex normal
end
lineTmp = lines(idxVertexNormal);
VertexNormal = zeros(length(idxVertexNormal),3);
lineTmp = strrep(lineTmp,'vn ','');
for ifacet = 1:length(lineTmp)
    ix = sscanf(lineTmp{ifacet},'%f %f %f');
    VertexNormal(ifacet,:) = [ix(1) ix(2) ix(3)];  % vertex normal values
end
lineTmp = lines(idxVertex);
Vertex = zeros(length(idxVertex),3);
lineTmp = strrep(lineTmp,'v ','');
for ifacet = 1:length(lineTmp)
    ix = sscanf(lineTmp{ifacet},'%f %f %f');
    Vertex(ifacet,:) = [ix(1) ix(2) ix(3)];  % vertex values
end
clear lineTmp

%% assemble as convenient structure array of components
ncomp = size(idxStartOfComponent,1);
nvert = size(Vertex,1);
nfacet = size(facetIdxV,1);
idxStartOfComponent = [idxStartOfComponent' length(lines)]';
materialName = strrep(lines(idxMaterialDefinition),'usemtl ','');
for icomp = 1:ncomp
    iFacet = find(idxStartOfComponent(icomp) < idxFacet & idxFacet <= idxStartOfComponent(icomp+1));
    wobj(icomp,1).fv = facetIdxV(iFacet,:);
    wobj(icomp,1).fvn = facetIdxVN(iFacet,:);
    wobj(icomp,1).materialName = materialName{icomp};
    iMat = find(strcmp(materials.Name,materialName{icomp}));
    wobj(icomp,1).Ka = materials.Ka(iMat);
    wobj(icomp,1).Kd = materials.Kd(iMat);
    wobj(icomp,1).Ks = materials.Ks(iMat);
    wobj(icomp,1).Color = materials.Color(iMat,:);
    wobj(icomp,1).Illum = materials.Illum(iMat);
    wobj(icomp,1).Ns = materials.Ns(iMat);
    wobj(icomp,1).Tr = materials.Tr(iMat);
end

%% store the component structures
save(fileMat,'wobj','Vertex','VertexNormal','-append')


