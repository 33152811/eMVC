unit eMVC.ViewCreator;

interface

uses
  Windows, SysUtils,
  eMVC.OTAUtilities,
  eMVC.FileCreator,
  ToolsApi,
  eMVC.BaseCreator;

type
  TViewCreator = class(TBaseCreator)
  public
    constructor Create(const APath: string = ''; ABaseName: string = '';
      AUnNamed: Boolean = true; AnAncestorName: string = 'Form'); reintroduce;
    function GetFormName: string; override;
    function GetCreatorType: string; override;
    function GetImplFileName: string; override;
    function NewImplSource(const ModuleIdent, FormIdent, AncestorIdent: string): IOTAFile; override;
    procedure FormCreated(const FormEditor: IOTAFormEditor); override;
  end;

implementation

uses eMVC.toolbox;

{ TViewCreator }

constructor TViewCreator.Create(const APath: string = ''; ABaseName: string = '';
  AUnNamed: Boolean = true; AnAncestorName: string = 'Form');
begin
  inherited Create(APath, ABaseName, AUnNamed);
  SetAncestorName(AnAncestorName);
end;

function TViewCreator.GetImplFileName: string;
begin
  result := self.getpath + GetBaseName + 'View.pas';
end;

function TViewCreator.getFormName: string;
begin
  result := 'View' + GetBaseName;
end;

function TViewCreator.NewImplSource(const ModuleIdent,
  FormIdent, AncestorIdent: string): IOTAFile;
begin
  if GetCreatorType = sForm then
    Result := TFileCreator.Create(ModuleIdent, FormIdent, AncestorIdent, cView)
  else
    Result := TFileCreator.Create(ModuleIdent, FormIdent, AncestorIdent, cClass);
end;

procedure TViewCreator.FormCreated(const FormEditor: IOTAFormEditor);
begin
  // One way to get the FormEditor to create Components.  The TButtons are
  // created TProjectCreatorWizard.Execute method.
  inherited;
end;

function TViewCreator.GetCreatorType: string;
begin

  if (GetAncestorName = 'FORM') or (GetAncestorName = 'FRAME') then
    Result := sForm
  else
    result := sUnit;

  debug('TViewCreator.GetCreatorType=' + GetAncestorName + ',Type=' + result);
end;

end.

