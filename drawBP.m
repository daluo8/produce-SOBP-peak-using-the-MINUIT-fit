clc
clear
m1=csvread('dosedata/mydose_1.csv',8,2);
x1=m1(:,1);
y1=m1(:,2);
m2=csvread('dosedata/mydose_2.csv',8,2);
x2=m2(:,1);
y2=m2(:,2);
m3=csvread('dosedata/mydose_3.csv',8,2);
x3=m3(:,1);
y3=m3(:,2);
m4=csvread('dosedata/mydose_4.csv',8,2);
x4=m4(:,1);
y4=m4(:,2);
m5=csvread('dosedata/mydose_5.csv',8,2);
x5=m5(:,1);
y5=m5(:,2);
m6=csvread('dosedata/mydose_6.csv',8,2);
x6=m6(:,1);
y6=m6(:,2);
m7=csvread('dosedata/mydose_7.csv',8,2);
x7=m7(:,1);
y7=m7(:,2);
m8=csvread('dosedata/mydose_8.csv',8,2);
x8=m8(:,1);
y8=m8(:,2);
m9=csvread('dosedata/mydose_9.csv',8,2);
x9=m9(:,1);
y9=m9(:,2);
m10=csvread('dosedata/mydose_10.csv',8,2);
x10=m10(:,1);
y10=m10(:,2);
m11=csvread('dosedata/mydose_11.csv',8,2);
x11=m11(:,1);
y11=m11(:,2);
x=flipud(x1)
y=y1+y2+y3*0.50+y4*0.37+y5*0.35+y6*0.22+y7*0.43+y8*0+y9*0.37+y10*0.13+y11*0.26
% plot(x,y1,'-')
% plot(x,y2,'-')
% hold on
% plot(x,y3*0.48,'-')
% hold on
% plot(x,y4*0.38,'-')
% hold on
% plot(x,y5*0.36,'-')
% hold on
% plot(x,y6*0.21,'-')
% hold on
% plot(x,y7*0.44,'-')
% hold on
% plot(x,y8*0,'-')
% hold on
% plot(x,y9*0.32,'-')
% hold on
% plot(x,y10*0.32,'-')
% hold on
plot(x,y,'-')
y2
% legend('1.0,1.00','1.5,1.00','2.0,0.48','2.5,0.38','3.0,0.36','3.5,0.21','4.0,0.44','5.5,0.00','6.0,0.32','6.5,0.32')
% %axis([0 100])
%text(330,1.2*10^-7,'d(mm),w')
set(gca,'XTick',0:40:400)
y10=flipud(y10)
[t,u]=max(y10);
xlabel('0.1mm')
ylabel('Gy')
title('Dose-Depth Curve')
