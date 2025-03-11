unit BallU;

interface

uses
  SysUtils, SpherePas;

type
  Colored = (RED, GREEN, BLUE, CYAN, YELLOW, WHITE, BLACK);

  Ball = class(TSphere)
  private
    theName: String;
    c: Colored;
    SpecificWeight: Real;
    function GetVolume: Real;
  public
    constructor Create(ar, aweight: Real; const initName: String; initColor: Colored);
    procedure SetName(newName: String);
    procedure SetColor(newColor: Colored);
    function GetName: String;
    function GetColor: Colored;
    function GetColorName: String;
    function GetWeight: Real;
    function GetBallInfo: String;
    property Volume: Real read GetVolume;
  end;

implementation

constructor Ball.Create(ar, aweight: Real; const initName: String; initColor: Colored);
begin
  inherited Create(ar);
  SpecificWeight := aweight;
  theName := initName;
  c := initColor;
end;

procedure Ball.SetName(newName: String);
begin
  theName := newName;
end;

procedure Ball.SetColor(newColor: Colored);
begin
  c := newColor;
end;

function Ball.GetName: String;
begin
  Result := theName;
end;

function Ball.GetColor: Colored;
begin
  Result := c;
end;

function Ball.GetColorName: String;
begin
  case c of
    RED: Result := 'RED';
    GREEN: Result := 'GREEN';
    BLUE: Result := 'BLUE';
    CYAN: Result := 'CYAN';
    YELLOW: Result := 'YELLOW';
    WHITE: Result := 'WHITE';
    BLACK: Result := 'BLACK';
  end;
end;

function Ball.GetWeight: Real;
begin
  Result := inherited GetVolume * SpecificWeight;
end;

function Ball.GetBallInfo: String;
begin
  Result := 'Радіус: ' + FloatToStr(GetRadius) +
            ', Об''єм: ' + FloatToStr(Volume) + 
            ', Маса: ' + FloatToStr(GetWeight) +
            ', Колір: ' + GetColorName + 
            ', Ім''я: ' + GetName;
end;

function Ball.GetVolume: Real;
begin
  Result := inherited GetVolume;
end;

end.

