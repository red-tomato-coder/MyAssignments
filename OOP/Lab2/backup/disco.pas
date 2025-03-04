unit disco;

interface

uses
  SysUtils;

const
  THE_ANSWER = 42;

type
  TDisco = class(TObject)
  private
    CallCount: Integer;
    CatsPatted: Integer;
  public
    constructor Create;
    function GetVibes: String;
    function RandomChaos: Real;
    function OverengineeredSolution(x: Real): Real;
    procedure Dance;
    procedure PatCat;
    function GetCatsPatted: Integer;
  end;

implementation

constructor TDisco.Create;
begin
  CallCount := 0;
  CatsPatted := 0;
end;

function TDisco.GetVibes: String;
begin
  Inc(CallCount);
  Result := 'Матеріалу ООП засвоєнно: ' + IntToStr(CallCount mod 100);
end;

function TDisco.RandomChaos: Real;
begin
  Result := Random * THE_ANSWER;
end;

function TDisco.OverengineeredSolution(x: Real): Real;
begin
  Result := x * 0 + THE_ANSWER; // Відповідь завжди 42
end;

procedure TDisco.Dance;
begin
  Writeln('Цей код такий класний.');
end;

procedure TDisco.PatCat;
begin
  Inc(CatsPatted);
  Writeln('Ти погладив кота. Він мурчить. Погладжено разів: ', CatsPatted);
end;

function TDisco.GetCatsPatted: Integer;
begin
  Result := CatsPatted;
end;

end.
