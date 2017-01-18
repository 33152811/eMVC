  ModelHead =
    '  unit %ModelIdent;                                          ' + #10#13 +
    '                                                              ' + #10#13 +
    'interface                                                     ' + #10#13 +
    'uses Classes, forms, SysUtils, eMVC.patterns;                      ' + #10#13 +
    '                                                              ' + #10#13;

  ModelDef =
    'type                                                          ' + #10#13 +
    '  TModel%FormIdent = class(TObservable)                       ' + #10#13 +
    '  public                                                      ' + #10#13 +
    '    constructor Create;                                       ' + #10#13 +
    '    destructor Destroy; override;                             ' + #10#13 +
    '  end;                                                        ' + #10#13 +
    '                                                              ' + #10#13 ;

  ModelImpl =
    'constructor TModel%FormIdent.Create;                          ' + #10#13 +
    'begin                                                         ' + #10#13 +
    'end;                                                          ' + #10#13 +
    '                                                              ' + #10#13 +
    'destructor TModel%FormIdent.Destroy;                          ' + #10#13 +
    'begin                                                         ' + #10#13 +
    '  inherited;                                                  ' + #10#13 +
    'end;                                                          ' + #10#13 +
    '                                                              ' + #10#13 ;
  
  ModelCode =  ModelHead +ModelDef +
    '                                                              ' + #10#13 +
    'implementation                                                ' + #10#13 +
    '                                                              ' + #10#13 +
    '                                                              ' + #10#13 +
    ModelImpl+
    '                                                              ' + #10#13 +
    'end.                                                          ' + #10#13;
