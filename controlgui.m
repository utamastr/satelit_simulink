function varargout = controlgui(varargin)
% CONTROLGUI MATLAB code for controlgui.fig
%      CONTROLGUI, by itself, creates a new CONTROLGUI or raises the existing
%      singleton*.
%
%      H = CONTROLGUI returns the handle to a new CONTROLGUI or the handle to
%      the existing singleton*.
%
%      CONTROLGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CONTROLGUI.M with the given input arguments.
%
%      CONTROLGUI('Property','Value',...) creates a new CONTROLGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before controlgui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to controlgui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help controlgui

% Last Modified by GUIDE v2.5 13-Jan-2014 22:39:06

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @controlgui_OpeningFcn, ...
                   'gui_OutputFcn',  @controlgui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before controlgui is made visible.
function controlgui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to controlgui (see VARARGIN)

% Choose default command line output for controlgui
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes controlgui wait for user response (see UIRESUME)
% uiwait(handles.figure1);

% Mengatur tombol mana yang di OFF kan agar tidak bisa diklik
% -----------------------------------------------------------
set(handles.run,'Enable','off');
% set(handles.next,'Enable','off');
set(handles.stop,'Enable','off');


% --- Outputs from this function are returned to the command line.
function varargout = controlgui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in run.
function run_Callback(hObject, eventdata, handles)
% hObject    handle to run (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.run,'Enable','off');
set(handles.ready,'Enable','off');
set(handles.stop,'Enable','on');

Model_File='SatDinModel_3';
set_param(Model_File,'SimulationCommand','start')


% --- Executes on button press in next.
function next_Callback(hObject, eventdata, handles)
% hObject    handle to next (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in stop.
function stop_Callback(hObject, eventdata, handles)
% hObject    handle to stop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Model_File='SatDinModel_3';
set_param(Model_File,'SimulationCommand','pause')
set_param(Model_File,'SimulationCommand','stop')
set(handles.stop,'Enable','off')
set(handles.ready,'Enable','on')


% --- Executes on button press in ready.
function ready_Callback(hObject, eventdata, handles)
% hObject    handle to ready (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Ambil data Sikap Awal Satelit dari MATLAB GUI
teta1_0 = get(handles.t01,'String');
teta2_0 = get(handles.t02,'String');
teta3_0 = get(handles.t03,'String');
 
teta1_target = get(handles.tx1,'String');
teta2_target = get(handles.tx2,'String');
teta3_target = get(handles.tx3,'String');
 
wx_0 = get(handles.wx,'String');
wy_0 = get(handles.wy,'String');
wz_0 = get(handles.wz,'String');

Att_Mode = get(handles.TesRadio,'String');

% Ambil data TEST Reaction Wheel dari MATLAB GUI
%-----------------------------------------------
wRWx_cmd = str2double(get(handles.w_rw_x,'String'))*2*3.14159/60;
wRWy_cmd = str2double(get(handles.w_rw_y,'String'))*2*3.14159/60;
wRWz_cmd = str2double(get(handles.w_rw_z,'String'))*2*3.14159/60;
 
wRWx_cmnd =num2str(wRWx_cmd);
wRWy_cmnd =num2str(wRWy_cmd);
wRWz_cmnd =num2str(wRWz_cmd);

% Membuka model simulink
Model_File='SatDinModel_3';
open_system(Model_File);

% Mengeset parameter awal satelit
set_param([Model_File '/AttitudeMode'],'value',Att_Mode)
set_param([Model_File '/SatelliteChars/w_0'],'value',['[' wx_0 ' ' wy_0 ' ' wz_0 ']'])
set_param([Model_File '/SatelliteChars/teta_0'],'value',['[' teta1_0 ' ' teta2_0 ' ' teta3_0 ']'])
set_param([Model_File '/teta_XXX'],'value',['[' teta1_target ' ' teta2_target ' ' teta3_target ']'])
set_param([Model_File '/w_RW_cmd'],'value',['[' wRWx_cmnd ' ' wRWy_cmnd ' ' wRWz_cmnd ']'])
set(handles.run,'Enable','on')


function w_rw_x_Callback(hObject, eventdata, handles)
% hObject    handle to w_rw_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of w_rw_x as text
%        str2double(get(hObject,'String')) returns contents of w_rw_x as a double


% --- Executes during object creation, after setting all properties.
function w_rw_x_CreateFcn(hObject, eventdata, handles)
% hObject    handle to w_rw_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function w_rw_y_Callback(hObject, eventdata, handles)
% hObject    handle to w_rw_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of w_rw_y as text
%        str2double(get(hObject,'String')) returns contents of w_rw_y as a double


% --- Executes during object creation, after setting all properties.
function w_rw_y_CreateFcn(hObject, eventdata, handles)
% hObject    handle to w_rw_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function w_rw_z_Callback(hObject, eventdata, handles)
% hObject    handle to w_rw_z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of w_rw_z as text
%        str2double(get(hObject,'String')) returns contents of w_rw_z as a double


% --- Executes during object creation, after setting all properties.
function w_rw_z_CreateFcn(hObject, eventdata, handles)
% hObject    handle to w_rw_z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tx1_Callback(hObject, eventdata, handles)
% hObject    handle to tx1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tx1 as text
%        str2double(get(hObject,'String')) returns contents of tx1 as a double


% --- Executes during object creation, after setting all properties.
function tx1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tx1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tx2_Callback(hObject, eventdata, handles)
% hObject    handle to tx2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tx2 as text
%        str2double(get(hObject,'String')) returns contents of tx2 as a double


% --- Executes during object creation, after setting all properties.
function tx2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tx2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tx3_Callback(hObject, eventdata, handles)
% hObject    handle to tx3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tx3 as text
%        str2double(get(hObject,'String')) returns contents of tx3 as a double


% --- Executes during object creation, after setting all properties.
function tx3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tx3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function t01_Callback(hObject, eventdata, handles)
% hObject    handle to t01 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of t01 as text
%        str2double(get(hObject,'String')) returns contents of t01 as a double


% --- Executes during object creation, after setting all properties.
function t01_CreateFcn(hObject, eventdata, handles)
% hObject    handle to t01 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function t02_Callback(hObject, eventdata, handles)
% hObject    handle to t02 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of t02 as text
%        str2double(get(hObject,'String')) returns contents of t02 as a double


% --- Executes during object creation, after setting all properties.
function t02_CreateFcn(hObject, eventdata, handles)
% hObject    handle to t02 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function t03_Callback(hObject, eventdata, handles)
% hObject    handle to t03 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of t03 as text
%        str2double(get(hObject,'String')) returns contents of t03 as a double


% --- Executes during object creation, after setting all properties.
function t03_CreateFcn(hObject, eventdata, handles)
% hObject    handle to t03 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function wx_Callback(hObject, eventdata, handles)
% hObject    handle to wx (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wx as text
%        str2double(get(hObject,'String')) returns contents of wx as a double


% --- Executes during object creation, after setting all properties.
function wx_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wx (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function wy_Callback(hObject, eventdata, handles)
% hObject    handle to wy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wy as text
%        str2double(get(hObject,'String')) returns contents of wy as a double


% --- Executes during object creation, after setting all properties.
function wy_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function wz_Callback(hObject, eventdata, handles)
% hObject    handle to wz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wz as text
%        str2double(get(hObject,'String')) returns contents of wz as a double


% --- Executes during object creation, after setting all properties.
function wz_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in tumbling.
function tumbling_Callback(hObject, eventdata, handles)
% hObject    handle to tumbling (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of tumbling
tulis = sprintf('%.2f', 1.0);
set(handles.TesRadio,'String',tulis);
set(handles.detumbling,'Value',0.0);
set(handles.StableInertial,'Value',0.0);
set(handles.targetpointing,'Value',0.0);
set(handles.test_rw,'Value',0.0);


% --- Executes on button press in detumbling.
function detumbling_Callback(hObject, eventdata, handles)
% hObject    handle to detumbling (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of detumbling
tulis = sprintf('%.2f', 2.0);
set(handles.TesRadio,'String',tulis);
set(handles.tumbling,'Value',0.0);
set(handles.StableInertial,'Value',0.0);
set(handles.targetpointing,'Value',0.0);
set(handles.test_rw,'Value',0.0);


% --- Executes on button press in StableInertial.
function StableInertial_Callback(hObject, eventdata, handles)
% hObject    handle to StableInertial (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of StableInertial
tulis = sprintf('%.2f', 3.0);
set(handles.TesRadio,'String',tulis);
set(handles.tumbling,'Value',0.0);
set(handles.detumbling,'Value',0.0);
set(handles.targetpointing,'Value',0.0);
set(handles.test_rw,'Value',0.0);


% --- Executes on button press in targetpointing.
function targetpointing_Callback(hObject, eventdata, handles)
% hObject    handle to targetpointing (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of targetpointing
tulis = sprintf('%.2f', 4.0);
set(handles.TesRadio,'String',tulis);
set(handles.tumbling,'Value',0.0);
set(handles.detumbling,'Value',0.0);
set(handles.StableInertial,'Value',0.0);
set(handles.test_rw,'Value',0.0);


% --- Executes on button press in test_rw.
function test_rw_Callback(hObject, eventdata, handles)
% hObject    handle to test_rw (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of test_rw
tulis = sprintf('%.2f', 5.0);
set(handles.TesRadio,'String',tulis);
set(handles.tumbling,'Value',0.0);
set(handles.detumbling,'Value',0.0);
set(handles.StableInertial,'Value',0.0);
set(handles.targetpointing,'Value',0.0);
