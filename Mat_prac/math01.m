% x=0:0.1:4*pi;
% y= sin(x);
% z = exp(-x/3)*sin(x);
% plot(x,y)
% hold on
% plot(z);

% x = linspace(0,4*pi,100);
% y1 = exp(-x/3);
% y2 = sin(x);
% y = y1.*y2;
% plot(x,y)
% title('さよなら');
% xlabel('x');
% ylabel('exp(-x/3)*sin(x)');

% x = linspace(1,10,100);
% y1 = cos(x);
% y2 = exp(x);
% y3 = log(x);
% y4 = log2(x);
% subplot(2,2,1)
% plot(x,y1)
% title('This is cos(x)');
% xlabel('x');
% ylabel('cos(x)');
% subplot(2,2,2)
% plot(x,y2)
% title('This is exp(x)');
% xlabel('x');
% ylabel('exp(x)');
% subplot(2,2,3)
% plot(x,y3)
% title('This is log(x)');
% xlabel('x');
% ylabel('log(x)');
% subplot(2,2,4)
% plot(x,y4)
% title('This is log2(x)');
% xlabel('x');
% ylabel('log2(x)');

% x = linspace (-5,5,200);
% y = x;
% [xx yy] = meshgrid(x,y);
% z = cos(xx.*yy) + xx.^2;
% surf(xx,yy,z)
% shading interp

%-----------
%
%
%
%
%-----------

% function y = piecewise_func(x)  
%     y(x <= -5) = sin(x(x <= -5));  
%     y(x <= 0 & x > -5) = cos(x(x <= 0 & x > -5));  
%     y(x <= 5 & x > 0) = exp(x(x <= 5 & x > 0));  
%     y(x > 5) = log(x(x > 5));
% end
% x = -5:0.1:10; 
% y = piecewise_func(x);
% plot(x, y);
% xlabel('x');
% ylabel('f(x)');
% title('Plot of the Piecewise Function');


% x = linspace(-20,20,400);
% for i = 1:400 
%     if x(i)<-10
%         y(i) = x(i)^2;
%     elseif x(i)<0
%         y(i) = sin(x(i));    
%     elseif x(i)<10
%         y(i) = exp(-x(i));
%     else 
%         y(i) = log(x(i));        
% 
%     end
% end
% plot(x, y);
% xlabel('x');
% ylabel('f(x)');
% title('Plot of the Piecewise Function');

S = SumMust(100) + SumMust2(100) + factorialMust(50);