clc
clear
close all
m=csvread('dosedata/mydose_11.csv',8,2)
filename='dosedata/dosedata_11.txt'
x=m(:,1)
y=m(:,2)
y1=flipud(y)
plot(x,y1,'-')
sum=0
sum0=0
% calculate dose for normal tissue
for i=1:180
    sum=sum+y1(i)*0.1
end
sum=sum/18
%calculate dose for tumor 
for i=181:280
    sum0=sum0+y1(i)*0.1
end
sum0=sum0/10
%sum1=0
yt=y1(181:280)
%inputfile

fid=fopen(filename,'w')
for i=1:100
    fprintf(fid,'%g ',yt(i))
end
fclose(fid)
% sum=10^6*sum/2500
% yt=y1(9:60)
% meanyt=mean(yt)
% variance=0
% for i=9:60
%     variance=variance+(y1(i)-meanyt)^2
% end
% variance=variance/52
% s=sqrt(variance)
% res=s/sum
