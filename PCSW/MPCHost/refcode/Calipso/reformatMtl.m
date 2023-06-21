%% *reformatMtl*
% convert output
%% *prerequisites*
% download the NASA 3D models
% https://nasa3d.arc.nasa.gov/detail/calipso
% and any other one you want that has an ascii color fbx format
%
% download and install FBX Converter from Autodesk (2013)
% https://www.autodesk.com/developer-network/platform-technologies/fbx-converter-archives
% use this to convert the NASA Calipso fbx to an .obj (wavefront)
% format.
%% *mtl*
% An entry in the mtl file is:
% newmtl cal_brass
% Ka 0.200000 0.200000 0.200000
% Kd 0.400000 0.231373 0.000000
% Ks 0.814379 0.814379 0.814379
% illum 2
% Ns 15.999999
% Tr 1.000000
%% *history*
% WHEN      WHO    WHY/WHAT
% 20190406  mnoah  models for astronomy education
%% *start*
%%
fileObj = 'calipso_v016_trip.mtl';

%% read the data file
str = fileread(fileObj);
lines = regexp(str, '\r\n|\r|\n', 'split');
lines = lines';

%% reformat the materials
idx = find(contains(lines,'# '));
lines(idx) = [];
idx = find(contains(lines,'newmtl'));
MaterialName = strtrim(strrep(lines(idx),'newmtl ',''));
nMat = size(MaterialName,1);
idx = find(contains(lines,'Ka'));
strKa = cell2mat(strtrim(strrep(lines(idx),'Ka ','')));
idx = find(contains(lines,'Kd'));
strKd = cell2mat(strtrim(strrep(lines(idx),'Kd ','')));
idx = find(contains(lines,'Ks'));
strKs = cell2mat(strtrim(strrep(lines(idx),'Ks ','')));
idx = find(contains(lines,'illum'));
strIllum = cell2mat(strtrim(strrep(lines(idx),'illum ','')));
idx = find(contains(lines,'Ns'));
strNs = strtrim(strrep(lines(idx),'Ns ',''));
idx = find(contains(lines,'Tr'));
strTr = cell2mat(strtrim(strrep(lines(idx),'Tr ','')));
Ka = zeros(nMat,1);
Kd = zeros(nMat,3);
Ks = zeros(nMat,1);
Illum = zeros(nMat,1);
Ns = zeros(nMat,1);
Tr = zeros(nMat,1);
for iMat = 1:nMat
    x = sscanf(strKa(iMat,:),'%f %f %f'); Ka(iMat) = x(1);
    x = sscanf(strKd(iMat,:),'%f %f %f'); Kd(iMat,:) = x';
    x = sscanf(strKs(iMat,:),'%f %f %f'); Ks(iMat) = x(1);
    x = sscanf(strIllum(iMat,:),'%f %f %f'); Illum(iMat) = x(1);
    x = sscanf(strNs{iMat,:},'%f %f %f'); Ns(iMat) = x(1);
    x = sscanf(strTr(iMat,:),'%f %f %f'); Tr(iMat) = x(1);
end

%% *material table*
% in matlab plots the materials vector just has one Ka, Kd, Ks dimension,
% so the Kd which has color information goes to the vector colors or the
% face colors
materials = table(MaterialName,Ka,mean(Kd')',Ks,Kd,Illum,Ns,Tr, ...
    'VariableNames',{'Name','Ka','Kd','Ks','Color','Illum','Ns','Tr'});

if (exist('calipso.mat','file'))
    save('calipso.mat','materials','-append');
else
    save('calipso.mat','materials');
end