clear all
close all

h2f = figure('Name','3 Plots — Click or Move Mouse','NumberTitle','off');
h2a = axes(h2f);

% % Create 3 stacked axes
% ax(1) = subplot(3,1,1,'Parent',f);
% ax(2) = subplot(3,1,2,'Parent',f);
% ax(3) = subplot(3,1,3,'Parent',f);
% 
% % Optional: change cursor when over an axes for feedback
% f.WindowButtonDownFcn = @(~,~) motionUpdate(f, ax);
% 
% % ---- Callback: mouse motion update ----
% function motionUpdate(figHandle, axesArray)
%     % Determine which axes the pointer is over and display coords
%     currentPoint = figHandle.CurrentPoint; % in pixels
%     fprintf("Current Point       : %d\n",currentPoint);
%     fprintf("AxesArray 1 Position: %d\n",axesArray(1).Position);
%     fprintf("AxesArray 2 Position: %d\n",axesArray(2).Position);
%     fprintf("AxesArray 3 Position: %d\n",axesArray(3).Position);
%     disp("")
%     pause(.5)
% end
