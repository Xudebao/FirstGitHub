close all;
figure(1);
plot3(x(:,1),x(:,3),x(:,5),'r-','linewidth',2);
hold on
plot3(1/2*cos(t/2),1/2*sin(t/2),2+t/10,'k-','linewidth',2);
axis([-0.6,0.6,-0.6,0.6]);
grid on
xlabel('x');ylabel('y');zlabel('z');
% figure(2);
% subplot(311);
% plot(t,x(:,1)-0.5*cos(t/2),'b','linewidth',2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
% xlabel('Time(s)');ylabel('e_x');
% subplot(312);
% plot(t,x(:,3)-0.5*sin(t/2),'b','linewidth',2);
% xlabel('Time(s)');ylabel('e_y');
% subplot(313);
% plot(t,x(:,5)-(2+t/10),'b','linewidth',2);
% xlabel('Time(s)');ylabel('e_z');
% 
% figure(3);
% subplot(311);
% plot(t,Angle(:,1)/pi*180,'r',t,x(:,7)/pi*180,'k','linewidth',2);
% legend('\theta_d (degree)','\theta (degree)');
% subplot(312);
% plot(t,Angle(:,2)/pi*180,'r',t,x(:,9)/pi*180,'k','linewidth',2);
% legend('\psi_d (degree)','\psi (degree)');
% subplot(313);
% plot(t,60*t./t,'r--',t,x(:,11)/pi*180,'b','linewidth',2);
% legend('\phid(degree)','\phi (degree)');
% 
% figure(4);
% subplot(411);
% plot(t,ut(:,1),'k','linewidth',2);
% legend('u1');
% subplot(412);
% plot(t,ut(:,2),'k','linewidth',2);
% legend('u2');
% subplot(413);
% plot(t,ut(:,3),'k','linewidth',2);
% legend('u3');
% subplot(414);
% plot(t,ut(:,4),'k','linewidth',2);
% legend('u4');
% 
% %以下3张图是为了更加清晰地显示无人机角度的变化
% figure(5);
% plot(t,Angle(:,1)/pi*180,'r',t,x(:,7)/pi*180,'k','linewidth',2);
% axis([0,30,-10,10]);
% legend('\theta_d (degree)','\theta (degree)');
% 
% figure(6);
% plot(t,Angle(:,2)/pi*180,'r',t,x(:,9)/pi*180,'k','linewidth',2);
% axis([0,30,-10,10]);
% legend('\psi_d (degree)','\psi (degree)');
% 
% figure(7);
% plot(t,60*t./t,'r--',t,x(:,11)/pi*180,'b','linewidth',2);
% axis([0,30,0,70]);
% legend('\phid(degree)','\phi (degree)');

