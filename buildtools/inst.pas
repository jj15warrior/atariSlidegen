uses crt, graph;

var
    i:byte;
begin
    initgraph(11);
    i :=0;
    repeat
    begin
        setcolor(i);
        bar(i*3,0,i*3+3,192);
        i := i + 1;
    end;
    until i=16;
    repeat until false;
end.