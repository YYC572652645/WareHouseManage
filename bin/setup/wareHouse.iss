; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "WareHouseManageSystem"
#define MyAppVersion "1.0"
#define MyAppPublisher "YunNiu"
#define MyAppExeName "WareHouseManageSystem.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{AA33B075-FB99-4472-B04A-98AE373C0BE5}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={pf}\WareHouseManageSystem
DisableProgramGroupPage=yes
OutputDir=C:\Users\Administrator\Desktop
OutputBaseFilename=WareHouseManageSystem
SetupIconFile=C:\Users\Administrator\Desktop\bin\app.ico
Compression=lzma
SolidCompression=yes
WizardImageFile = app.bmp
WizardSmallImageFile = small.bmp

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Users\Administrator\Desktop\bin\WareHouseManageSystem.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Administrator\Desktop\bin\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon
Name: "{userdesktop}\{#MyAppExeName}"; Filename: "{app}\{#MyAppExeName}";WorkingDir: "{app}"

[Languages]  
Name: "eng"; MessagesFile: "compiler:English.isl"  
Name: "chs"; MessagesFile: "compiler:Languages\ChineseTrad.isl"  

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
