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
    rows_to_lists(Rows, Lists).

rows_to_lists(Rows, Lists) :- maplist(row_to_list, Rows, Lists).

row_to_list(Row, List) :-
    Row =.. [row|List].