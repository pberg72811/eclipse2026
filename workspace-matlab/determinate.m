x = [ 0 4 4 0 0 ];
y = [ 0 0 4 4 0 ];

bcx = [ 3 4 4 3 3 ];
bcy = [ 0 0 1 1 0 ];

bcx_ = [ 0 1 1 0 0];
bcy_ = [ 3 3 4 4 3];

bd2x  = [ 0 1 0 0];
bd2y  = [ 0 3 3 0];

bd2x_ = [ 3 4 4 3 ];
bd2y_ = [ 1 1 4 1 ];

ac2x  = [ 1 4 1 1 ];
ac2y  = [ 3 4 4 3 ];

ac2x_ = [ 0 3 3 0 ];
ac2y_ = [ 0 0 1 0 ];

% finalx = [ x bcx bcx_ bd2x bd2x_ ac2x ac2x_ ];
% finaly = [ y bcy bcy_ bd2y bd2y_ ac2y ac2y_ ];

plot(x,y);
hold on;
axis square;
plot(bcx,bcy);
plot(bcx_, bcy_);
plot(bd2x, bd2y);
plot(bd2x_, bd2y_);
plot(ac2x, ac2y);
plot(ac2x_, ac2y_);