% A start up script for MATLAB.
%
user_Dir = getenv("USERPROFILE");                % DEFINE USER FOLDER.
eclpsDir = strcat(user_Dir,"\Eclipse");          % DEFINE ECLIPSE FOLDER.
work_Dir = strcat(eclpsDir,"\workspace-matlab"); % DEFINE MATLAB WORKING FOLDER.

addpath(work_Dir);

dispTopOfPathList();

javaEnvironment = strcat(user_Dir,"\AppData\Local\Programs\Java\ojdk21");
jenv(javaEnvironment);
jenv;

% javaaddpath( strcat(eclpsDir, "\jcc.jar") );


%-------------------------------------------------------------------------------------------------
function dispTopOfPathList()
%
% Display the top part of the PATH list.
%-------------------------------------------------------------------------------------------------
    list = path;
    x = strsplit(list,';')';
    disp("YOUR PATH IS:");
    disp(" ");
    disp( x(1:8) );
    disp("Plus the rest ...");
end