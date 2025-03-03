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
  Result := 'Vibes: ' + IntToStr(CallCount mod 100) + '% disco';
end;

function TDisco.RandomChaos: Real;
begin
  Result := Random * THE_ANSWER;
end;

function TDisco.OverengineeredSolution(x: Real): Real;
begin
  Result := x * 0 + THE_ANSWER; // No matter what, the answer is 42
end;

procedure TDisco.Dance;
begin
  Writeln('The disco lights flash. You feel an uncontrollable urge to vibe.');
end;

procedure TDisco.PatCat;
begin
  Inc(CatsPatted);
  Writeln('You pat the cat. It purrs. Total pats: ', CatsPatted);
end;

function TDisco.GetCatsPatted: Integer;
begin
  Result := CatsPatted;
end;

end.
