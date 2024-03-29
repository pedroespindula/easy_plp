:- module(runner, [runner/2]).
:- use_module(downloader).

get_out(Input_value, Output_value):-
    process_create(path(bash),["-c","./run"],[stdin(pipe(In)),stdout(pipe(Out))]),
    write(In,Input_value),
    close(In),
    read_line_to_codes(Out,Result),
    close(Out),atom_codes(Atom,Result),
    atom_to_term(Atom,Output_value,[]).

compare_values(V,V,".").
compare_values(_,_,"f").

generate_list_results([],[]).
generate_list_results([X|Y],[X1|Y1]):-
    get_out(X,X1),
    generate_list_results(Y,Y1).

create_result([X|[]],[Y|_],Result):-
    compare_values(X,Y,Result).

create_result([X1|Y1],[X2|Y2],Result):-
    create_result(Y1,Y2,R),
    compare_values(X1,X2,R1),
    string_concat(R1,R,Result).

getByIndex([],_,[]).
getByIndex([H|T],Index, [H1|T1]):-
    nth0(Index,H,H1),
    getByIndex(T,Index, T1).

runner(NomeArquivoCompilar, NomeArquivoCsv):-
    process_create(path(gcc),[NomeArquivoCompilar,"-o","run"],[]),
    lerCsvRowList(NomeArquivoCsv, [_|Lists]),
    getByIndex(Lists,1, Inputs),
    getByIndex(Lists,2, Outs),
    generate_list_results(Inputs, Out),
    create_result(Out,Outs,Result),
    write(Result),
    process_create(path(bash),["-c","rm -rf run"],[]).
    

