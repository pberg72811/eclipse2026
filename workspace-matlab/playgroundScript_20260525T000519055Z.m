
% three_plots_mouse_interaction.m
f = figure('Name','3 Plots — Click or Move Mouse','NumberTitle','off');

% Create 3 stacked axes
ax(1) = subplot(3,1,1,'Parent',f);
ax(2) = subplot(3,1,2,'Parent',f);
ax(3) = subplot(3,1,3,'Parent',f);

% Example data and plot each axes; store index via UserData
t = linspace(0,10,500);
h1 = plot(ax(1), t, sin(t)); hold(ax(1),'on'); ax(1).UserData = 1;
h2 = plot(ax(2), t, cos(t)); hold(ax(2),'on'); ax(2).UserData = 2;
h3 = plot(ax(3), t, sin(2*t)); hold(ax(3),'on'); ax(3).UserData = 3;

% Make the plotted lines clickable
set([h1 h2 h3], 'ButtonDownFcn', @(src,ev) lineClick(src,ev));

% Optional: change cursor when over an axes for feedback
f.WindowButtonMotionFcn = @(~,~) motionUpdate(f, ax);

% ---- Callback: line click ----
function lineClick(~, ~)
    % gca is the axes containing the clicked object
    a = gca;
    cp = a.CurrentPoint;               % 2x3; use first row (x,y,z)
    x = cp(1,1); y = cp(1,2);
    idx = a.UserData;                  % which axes
    fprintf('Clicked axes %d: x = %.4g, y = %.4g\n', idx, x, y);
    % Example reaction: mark the point
    hold(a,'on');
    plot(a, x, y, 'ro', 'MarkerFaceColor','r');
end

% ---- Callback: mouse motion update ----
function motionUpdate(figHandle, axesArray)
    % Determine which axes the pointer is over and display coords
    currentPoint = figHandle.CurrentPoint; % in pixels
    hit = matlab.graphics.interaction.currentPoint2axes(figHandle, currentPoint);
    % hit is empty if not over an axes. Use fallback check:
    axOver = [];
    for k = 1:numel(axesArray)
        p = axesArray(k).Position; % normalized
        % Convert figure point to normalized: use inverse of pixels->normalized
    end
    % Simpler robust approach: loop axes and test if pointer is inside
    pointer = get(figHandle, 'CurrentPoint'); % pixel
    % Convert pixel to normalized coordinates
    figPos = figHandle.Position; % [left bottom width height] in pixels
    normX = pointer(1)/figPos(3); normY = pointer(2)/figPos(4);
    axOver = [];
    for k = 1:numel(axesArray)
        pos = axesArray(k).Position; % normalized
        if normX >= pos(1) && normX <= pos(1)+pos(3) && ...
           normY >= pos(2) && normY <= pos(2)+pos(4)
            axOver = axesArray(k);
            break
        end
    end

    % Update title with axes coordinates if over an axes
    if ~isempty(axOver)
        cp = axOver.CurrentPoint;
        x = cp(1,1); y = cp(1,2);
        axOver.Title.String = sprintf('Axes %d: x = %.3g, y = %.3g', axOver.UserData, x, y);
    else
        % clear titles when not over any axes
        for k = 1:numel(axesArray)
            axesArray(k).Title.String = '';
        end
    end
end