function createfigure(X1, Y1, titulo, dataname,tipo, ejey)
%CREATEFIGURE(X1, Y1)
%  X1:  vector of x data
%  Y1:  vector of y data

%  Auto-generated by MATLAB on 03-Nov-2017 17:11:13

% Create figure
figure1 = figure;set(figure1,'Visible','off');

% Create axes
axes1 = axes('Parent',figure1);
%% Uncomment the following line to preserve the X-limits of the axes
% xlim(axes1,[0 14]);
%% Uncomment the following line to preserve the Y-limits of the axes
% ylim(axes1,[4 18]);
box(axes1,'on');
hold(axes1,'on');

% Create plot
plot1 = plot(X1,Y1,'DisplayName',dataname,'Marker','o','LineStyle',':',...
    'Color',[1 0 0]);

% Get xdata from plot for data statistics
xdata1 = get(plot1, 'xdata');
% Get ydata from plot for data statistics
ydata1 = get(plot1, 'ydata');
% Make sure data are column vectors
xdata1 = xdata1(:);
ydata1 = ydata1(:);


% Get axes xlim
axXLim1 = get(axes1, 'xlim');

% Find the max
ymax1 = max(ydata1);

maxValue1 = [ymax1 ymax1];
% Create plot
statLine1 = plot(axXLim1,maxValue1,'DisplayName',strcat('   ', tipo, ' m�ximo'),'Tag','max y',...
    'Parent',axes1,...
    'LineStyle','-.',...
    'Color',[0 0 1]);

% Set new line in proper position
setLineOrder(axes1, statLine1, plot1);

% Find the min
ymin1 = min(ydata1);

minValue1 = [ymin1 ymin1];
% Create plot
statLine2 = plot(axXLim1,minValue1,'DisplayName',strcat('   ', tipo, ' m�nimo'),'Tag','min y',...
    'Parent',axes1,...
    'LineStyle','-.',...
    'Color',[0 0.75 0.75]);

% Set new line in proper position
setLineOrder(axes1, statLine2, plot1);

% Create xlabel
xlabel({'Hebras'});

% Create ylabel
ylabel({ejey});

% Create title
title({titulo});

% Create legend
legend(axes1,'show');

grid on

saveas(figure1,strcat('figures/',titulo,'-',tipo,'.png'));

%-------------------------------------------------------------------------%
function setLineOrder(axesh1, newLine1, associatedLine1)
%SETLINEORDER(AXESH1,NEWLINE1,ASSOCIATEDLINE1)
%  Set line order
%  AXESH1:  axes
%  NEWLINE1:  new line
%  ASSOCIATEDLINE1:  associated line

% Get the axes children
hChildren = get(axesh1,'Children');
% Remove the new line
hChildren(hChildren==newLine1) = [];
% Get the index to the associatedLine
lineIndex = find(hChildren==associatedLine1);
% Reorder lines so the new line appears with associated data
hNewChildren = [hChildren(1:lineIndex-1);newLine1;hChildren(lineIndex:end)];
% Set the children:
set(axesh1,'Children',hNewChildren);

