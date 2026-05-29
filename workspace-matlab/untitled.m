x = randn(16,1);
y = randn(16,1);
plot(x,y)
plot(x,y,".");
hold on;
plot(mean(x),mean(y),"*")