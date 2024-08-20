uses crt, graph;

var
    i:byte;
begin
    initgraph(9+16);

    repeat
    begin
        setcolor(i);
        bar(i*5,0,i*5+5,192);
    end;
    until i=16;
    repeat until false;
end.