:- module(downloader, [downloader/1, lerCsvRowList/2]).
:- use_module(library(http/http_open)).

downloader(Exercise) :-
    URL = "https://raw.githubusercontent.com/pedroespindula/easy_plp/init-prolog/exercicios/",
    string_concat(URL, Exercise, PartialURL),
    string_concat(PartialURL, ".csv", CompleteURL),
    string_concat(Exercise, ".csv", File),
    http_open(CompleteURL, In, []),
    open(File, write, Stream),
    copy_stream_data(In, Stream),
    close(In).

lerCsvRowList(Exercise, Lists) :-
    csv_read_file(Exercise, Rows, []),
    rowsToLists(Rows, Lists).

getByIndex([],Index,[]).
getByIndex([H|T],Index, [H1|T1]):-
    nth0(Index,H,H1),
    getByIndex(T,Index, T1).

rowsToLists(Rows, Lists) :- maplist(rowToList, Rows, Lists).

rowToList(Row, List) :-
    Row =.. [row|List].
