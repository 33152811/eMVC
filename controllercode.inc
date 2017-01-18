FormViewCreate = 'Application.CreateForm(TView%FormIdent, view)';
NormalViewCreate = 'view := TView%FormIdent.create(nil)';
NormalViewDestory = 'freeAndNil(view)';

ControllerCode =
'unit %ModelIdent;                                                ' + #10#13 +
'                                                                  ' + #10#13 +
'interface                                                         ' + #10#13 +
'uses                                                              ' + #10#13 +
'SysUtils, forms, buttons, classes, controls,eMVC.patterns,             ' + #10#13 +
'%FormIdentMdl,%FormIdentView;                                     ' + #10#13 +
'                                                                  ' + #10#13 +
'type                                                              ' + #10#13 +
'  TController%FormIdent = class(TController)                      ' + #10#13 +
'    model: TModel%FormIdent;                                      ' + #10#13 +
'    view: TView%FormIdent;                                        ' + #10#13 +
'  protected                                                       ' + #10#13 +
'    Procedure DoCommand(Command: string; const args: string=''''); override; ' + #10#13 +
'  public                                                          ' + #10#13 +
'    Constructor Create;                                           ' + #10#13 +
'    Destructor Destroy; override;                                 ' + #10#13 +
'    Procedure OnClick(Sender: TObject); //for ieventListener      ' + #10#13 +
'    Procedure OnMouseEvent(Sender: TObject;                       ' + #10#13 +
'    Button: TMouseButton; Shift: TShiftState; X, Y: Integer);     ' + #10#13 +
'  end;                                                            ' + #10#13 +
'                                                                  ' + #10#13 +
'implementation                                                    ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.OnClick(Sender: TObject);         ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.OnMouseEvent(Sender: TObject;     ' + #10#13 +
'Button: TMouseButton; Shift: TShiftState; X, Y: Integer);         ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Constructor TController%FormIdent.Create;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  inherited;                                                      ' + #10#13 +
'  model := TModel%FormIdent.Create;                               ' + #10#13 +
'  %ViewCreation;                  ' + #10#13 +
'  model.RegObserver(view);                                        ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Destructor TController%FormIdent.destroy;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  freeAndNil(model);                                              ' + #10#13 +
'  %FreeView;                                             ' + #10#13 +
'  inherited;                                                        ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.DoCommand(Command: string; const args: string=''''); ' + #10#13 +
'begin                                                             ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'initialization                                                    ' + #10#13 +
'  ControlCenter.RegController(TController%FormIdent.Create);      ' + #10#13 +
'                                                                  ' + #10#13 +
'end.                                                              ' + #10#13;


ControllerCode2 =
'unit %ModelIdent;                                                ' + #10#13 +
'                                                                  ' + #10#13 +
'interface                                                         ' + #10#13 +
'uses                                                              ' + #10#13 +
'SysUtils, forms, buttons, classes, controls,patterns;             ' + #10#13 +
'                                                                  ' + #10#13 +
'type                                                              ' + #10#13 +
'  TController%FormIdent = class(TController)                      ' + #10#13 +
'    model: TModel%FormIdent;                                      ' + #10#13 +
'    view: TView%FormIdent;                                        ' + #10#13 +
'  protected                                                       ' + #10#13 +
'    Procedure DoCommand(Command: string; const args: string=''''); override; ' + #10#13 +
'  public                                                          ' + #10#13 +
'    Constructor Create;                                           ' + #10#13 +
'    Destructor Destroy; override;                                 ' + #10#13 +
'    Procedure OnClick(Sender: TObject); //for ieventListener      ' + #10#13 +
'    Procedure OnMouseEvent(Sender: TObject;                       ' + #10#13 +
'    Button: TMouseButton; Shift: TShiftState; X, Y: Integer);     ' + #10#13 +
'  end;                                                            ' + #10#13 +
'                                                                  ' + #10#13 +
'%ModelDef                                                        ' + #10#13 +
'                                                                  ' + #10#13 +
'%ViewDef                                                          ' + #10#13 +
'implementation                                                    ' + #10#13 +
'                                                                  ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.onClick(Sender: TObject);         ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.OnMouseEvent(Sender: TObject;     ' + #10#13 +
'Button: TMouseButton; Shift: TShiftState; X, Y: Integer);         ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Constructor TController%FormIdent.Create;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  inherited;                                                      ' + #10#13 +
'  model := TModel%FormIdent.Create;                               ' + #10#13 +
'  %ViewCreation;                                                  ' + #10#13 +
'  model.RegObserver(view);                                        ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Destructor TController%FormIdent.destroy;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  freeAndNil(model);                                              ' + #10#13 +
'  %FreeView;                                             ' + #10#13 +
'  inherited;                                                        ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.DoCommand(Command: string; const args: string=''''); ' + #10#13 +
'begin                                                             ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'%ModelImpl                                                        ' + #10#13 +
'                                                                  ' + #10#13 +
'%ViewImpl                                                         ' + #10#13 +
'initialization                                                    ' + #10#13 +
'  ControlCenter.RegController(TController%FormIdent.Create);      ' + #10#13 +
'                                                                  ' + #10#13 +
'end.                                                              ' + #10#13;



ControllerCodeWithoutModel =
'unit %ModelIdent;                                                ' + #10#13 +
'                                                                  ' + #10#13 +
'interface                                                         ' + #10#13 +
'uses                                                              ' + #10#13 +
'SysUtils, forms, buttons, classes, controls,eMVC.patterns,             ' + #10#13 +
'%FormIdentView;                                                   ' + #10#13 +
'                                                                  ' + #10#13 +
'type                                                              ' + #10#13 +
'  TController%FormIdent = class(TController)                      ' + #10#13 +
'    view: TView%FormIdent;                                        ' + #10#13 +
'  protected                                                       ' + #10#13 +
'    Procedure DoCommand(Command: string; const args: string=''''); override; ' + #10#13 +
'  public                                                          ' + #10#13 +
'    Constructor Create;                                           ' + #10#13 +
'    Destructor Destroy; override;                                 ' + #10#13 +
'    Procedure OnClick(Sender: TObject); //for ieventListener      ' + #10#13 +
'    Procedure OnMouseEvent(Sender: TObject;                       ' + #10#13 +
'    Button: TMouseButton; Shift: TShiftState; X, Y: Integer);     ' + #10#13 +
'  end;                                                            ' + #10#13 +
'                                                                  ' + #10#13 +
'%ModelDef                                                        ' + #10#13 +
'                                                                  ' + #10#13 +
'implementation                                                    ' + #10#13 +
'                                                                  ' + #10#13 +
'                                                                  ' + #10#13 +
'Constructor TController%FormIdent.Create;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  inherited;                                                      ' + #10#13 +
'  %ViewCreation;                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Destructor TController%FormIdent.destroy;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  %FreeView;                                                      ' + #10#13 +
'  inherited;                                                        ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.DoCommand(Command: string; const args: string=''''); ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.onClick(Sender: TObject);         ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.OnMouseEvent(Sender: TObject;     ' + #10#13 +
'Button: TMouseButton; Shift: TShiftState; X, Y: Integer);         ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +

'%ModelImpl                                                        ' + #10#13 +
'                                                                  ' + #10#13 +
'initialization                                                    ' + #10#13 +
'  ControlCenter.RegController(TController%FormIdent.Create);      ' + #10#13 +
'                                                                  ' + #10#13 +
'end.                                                              ' + #10#13;



ControllerCodeWithoutView =
'unit %ModelIdent;                                                ' + #10#13 +
'                                                                  ' + #10#13 +
'interface                                                         ' + #10#13 +
'uses                                                              ' + #10#13 +
'SysUtils, forms, buttons, classes, controls,eMVC.patterns,             ' + #10#13 +
'%FormIdentMdl;                                                    ' + #10#13 +
'                                                                  ' + #10#13 +
'type                                                              ' + #10#13 +
'  TController%FormIdent = class(TController)                      ' + #10#13 +
'    model: TModel%FormIdent;                                      ' + #10#13 +
'  protected                                                       ' + #10#13 +
'    Procedure DoCommand(Command: string; const args: string=''''); override; ' + #10#13 +
'  public                                                          ' + #10#13 +
'    Constructor Create;                                           ' + #10#13 +
'    Destructor Destroy; override;                                 ' + #10#13 +
'  end;                                                            ' + #10#13 +
'                                                                  ' + #10#13 +
'%ViewDef                                                          ' + #10#13 +
'                                                                  ' + #10#13 +
'implementation                                                    ' + #10#13 +
'                                                                  ' + #10#13 +
'                                                                  ' + #10#13 +
'Constructor TController%FormIdent.Create;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  inherited;                                                      ' + #10#13 +
'  model := TModel%FormIdent.Create;                               ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Destructor TController%FormIdent.destroy;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  freeAndNil(model);                                              ' + #10#13 +
'  inherited;                                                      ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.DoCommand(Command: string; const args: string=''''); ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'%ViewImpl                                                         ' + #10#13 +
'                                                                  ' + #10#13 +
'initialization                                                    ' + #10#13 +
'  ControlCenter.RegController(TController%FormIdent.Create);      ' + #10#13 +
'                                                                  ' + #10#13 +
'end.                                                              ' + #10#13;

ControllerCodeOnly =
'unit %ModelIdent;                                                ' + #10#13 +
'                                                                  ' + #10#13 +
'interface                                                         ' + #10#13 +
'uses                                                              ' + #10#13 +
'SysUtils, forms, buttons, classes, controls,patterns;             ' + #10#13 +
'                                                                  ' + #10#13 +
'type                                                              ' + #10#13 +
'  TController%FormIdent = class(TController)                      ' + #10#13 +
'  protected                                                       ' + #10#13 +
'    Procedure DoCommand(Command: string; const args: string=''''); override; ' + #10#13 +
'  public                                                          ' + #10#13 +
'    Constructor Create;                                           ' + #10#13 +
'    Destructor Destroy; override;                                 ' + #10#13 +
'  end;                                                            ' + #10#13 +
'                                                                  ' + #10#13 +
//    '%ModelDef                                                        ' + #10#13 +
//    '                                                                  ' + #10#13 +
//    '%ViewDef                                                          ' + #10#13 +
//    '                                                                  ' + #10#13 +
'implementation                                                    ' + #10#13 +
'                                                                  ' + #10#13 +
'                                                                  ' + #10#13 +
'Constructor TController%FormIdent.Create;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  inherited;                                                      ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Destructor TController%FormIdent.destroy;                         ' + #10#13 +
'begin                                                             ' + #10#13 +
'  inherited;                                                      ' + #10#13 +
'end;                                                              ' + #10#13 +
'                                                                  ' + #10#13 +
'Procedure TController%FormIdent.DoCommand(Command: string; const args: string=''''); ' + #10#13 +
'begin                                                             ' + #10#13 +
'                                                                  ' + #10#13 +
'end;                                                              ' + #10#13 +
//    '                                                                  ' + #10#13 +
//    '%ModelImpl                                                        ' + #10#13 +
//    '                                                                  ' + #10#13 +
//    '%ViewImpl                                                         ' + #10#13 +
'                                                                  ' + #10#13 +
'initialization                                                    ' + #10#13 +
'  ControlCenter.RegController(TController%FormIdent.Create);      ' + #10#13 +
'                                                                  ' + #10#13 +
'end.                                                              ' + #10#13;

