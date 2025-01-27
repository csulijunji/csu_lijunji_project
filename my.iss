; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "My Program"
#define MyAppVersion "1.5"
#define MyAppPublisher "My Company, Inc."
#define MyAppURL "http://www.example.com/"
#define MyAppExeName "shuzizhongnan.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{A90B04F3-FEE1-410B-8BF5-0C44302A0301}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DisableProgramGroupPage=yes
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\csuLogin\shuzizhongnan.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\config.ini"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\D3Dcompiler_47.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\encode.js"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\libEGL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\libGLESV2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\libmysql.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\libmysql.lib"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\opengl32sw.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\Qt5Network.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\Qt5Script.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\Qt5Sql.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\Qt5Svg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\shuzizhongnanPack.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\csuLogin\bearer\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\csuLogin\iconengines\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\csuLogin\imageformats\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\csuLogin\Output\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\csuLogin\platforms\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\csuLogin\sqldrivers\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\csuLogin\styles\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\csuLogin\translations\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

