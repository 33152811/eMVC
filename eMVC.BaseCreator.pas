unit eMVC.BaseCreator;

{**********************************************************************}
{ Copyright 2005 Reserved by Eazisoft.com                              }
{ File Name: BaseCreator.pas                                           }  
{ Author: Larry Le                                                     }
{ Description: Base Class of the all module creators                   }
{                                                                      }
{ History:                                                             }
{ - 1.0, 19 May 2006                                                   }
{   First version                                                      }
{                                                                      }
{ Email: linfengle@gmail.com                                           }
{                                                                      }
{ The contents of this file are subject to the Mozilla Public License }
{ Version 1.1 (the "License"); you may not use this file except in     }
{ compliance with the License. You may obtain a copy of the License at }
{ http://www.mozilla.org/MPL/                                          }
{                                                                      }
{ Software distributed under the License is distributed on an "AS IS"  }
{ basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See  }
{ the License for the specific language governing rights and           }
{ limitations under the License.                                       }
{                                                                      }
{ The Original Code is written in Delphi.                              }
{                                                                      }
{ The Initial Developer of the Original Code is Larry Le.              }
{ Copyright (C) eazisoft.com. All Rights Reserved.                     }
{                                                                      }
{**********************************************************************}

interface

uses
  Windows, SysUtils,
  eMVC.OTAUtilities,
  eMVC.FileCreator,
  ToolsApi,
  eMVC.ToolBox;

type

  TBaseCreator = class(TInterfacedObject, IOTACreator, IOTAModuleCreator)
  private
    FAncestorName: string;
    FPath: string;
    FBaseName: string;
    FUnnamed: boolean;
    procedure setBaseName(ABaseName: string);
  public
    constructor Create(const APath: string = ''; ABaseName: string = '';
      AUnNamed: Boolean = true); virtual;
    procedure setPath(APath: string);
    function getpath: string;
    // IOTACreator
    function GetCreatorType: string; virtual;
    function GetExisting: Boolean;
    function GetFileSystem: string;
    function GetOwner: IOTAModule;
    function GetUnnamed: Boolean; virtual;
    // IOTAModulCreator
    function GetAncestorName: string; virtual;
    function GetImplFileName: string; virtual;
    function GetIntfFileName: string;
    function GetFormName: string; virtual;
    function GetMainForm: Boolean; virtual;
    function GetShowForm: Boolean; virtual;
    function GetShowSource: Boolean;
    function NewFormFile(const FormIdent, AncestorIdent: string): IOTAFile;
    function NewImplSource(const ModuleIdent, FormIdent, AncestorIdent: string): IOTAFile; virtual;
    function NewIntfSource(const ModuleIdent, FormIdent, AncestorIdent: string): IOTAFile;
    procedure FormCreated(const FormEditor: IOTAFormEditor); virtual;

    property AncestorName: string read GetAncestorName;
    property FormName: string read GetFormName;
    property ImplFileName: string read GetImplFileName;
    property IntfFileName: string read GetIntfFileName;
    property MainForm: Boolean read GetMainForm;
    property ShowForm: Boolean read GetShowForm;
    property ShowSource: Boolean read GetShowSource;

    procedure SetAncestorName(AnAncestorName: string);
    function getBaseName: string;
    property BaseName: string read getBaseName write SetBaseName;
  end;

implementation

{ TSampleProjectCreatorModule }



function TBaseCreator.GetAncestorName: string;
begin
  Result := FAncestorName; // We will be deriving from TForm in this example
end;

procedure TBaseCreator.SetAncestorName(AnAncestorName: string);
var
  s: string;
begin
  s := uppercase(trim(AnAncestorName));
  if s = '' then
    self.FAncestorName := 'Object'
  else begin
    if Pos('T', s) = 1 then
      self.FAncestorName := Copy(S, 2, length(s))
    else
      self.FAncestorName := s;
  end;
  Debug('TBaseCreator.SetAncestorName:Parent Class=' + FAncestorName);
end;

function TBaseCreator.getBaseName: string;
begin
  result := self.FBaseName;
end;

constructor TBaseCreator.Create(const APath: string = ''; ABaseName: string = '';
  AUnNamed: Boolean = true);
begin
  self.FPath := APath;
  self.FBaseName := ABaseName;
  self.FUnnamed := AUnNamed;
end;

procedure TBaseCreator.setBaseName(ABaseName: string);
begin
  FBaseName := ABaseName;
end;

procedure TBaseCreator.setPath(APath: string);
begin
  self.FPath := APath;
end;

function TBaseCreator.getpath: string;
begin
  result := FPath;
end;

procedure TBaseCreator.FormCreated(const FormEditor: IOTAFormEditor);
begin
end;

function TBaseCreator.GetExisting: Boolean;
begin
  Result := False; // Create a new module
end;

function TBaseCreator.GetFileSystem: string;
begin
  Result := ''; // Default File System
end;

function TBaseCreator.GetFormName: string;
begin
  Result := GetBaseName;
end;

function TBaseCreator.GetImplFileName: string;
begin
  Result := '';
end;

function TBaseCreator.GetIntfFileName: string;
begin
  Result := '';
end;

function TBaseCreator.GetMainForm: Boolean;
begin
  Result := false;
end;

function TBaseCreator.GetOwner: IOTAModule;
begin
  // Owned by current project
  Result := GetCurrentProjectGroup;
  if Assigned(Result) then
    Result := (Result as IOTAProjectGroup).ActiveProject
  else
    Result := GetCurrentProject;
end;

function TBaseCreator.GetShowForm: Boolean;
begin
  Result := false;
end;

function TBaseCreator.GetShowSource: Boolean;
begin
  Result := True;
end;

function TBaseCreator.GetUnnamed: Boolean;
begin
  Result := self.FUnnamed; // true means Project needs to be named/saved
end;

function TBaseCreator.NewFormFile(const FormIdent,
  AncestorIdent: string): IOTAFile;
begin
  Result := nil;
end;

function TBaseCreator.NewImplSource(const ModuleIdent,
  FormIdent, AncestorIdent: string): IOTAFile;
begin
  //default create the normal class
  Result := TFileCreator.Create(ModuleIdent, FormIdent, AncestorIdent);
end;

function TBaseCreator.NewIntfSource(const ModuleIdent, FormIdent, AncestorIdent: string): IOTAFile;
begin
  Result := nil;
end;

function TBaseCreator.GetCreatorType: string;
begin
  Result := sUnit;
end;

end.

