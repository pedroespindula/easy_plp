:- module(config, [config/1, read_config/1]).

config_file('/home/pedro/.easy_plp.config').

config(Diretorio) :-
    config_file(ConfigFile),
    open(ConfigFile, write, Stream),
    write(Stream, Diretorio),
    close(Stream).

lerCsvRowList(Path, Lists) :-
    csv_read_file(Path, Rows, []),
    rows_to_lists(Rows, Lists).

rows_to_lists(Rows, Lists) :- maplist(row_to_list, Rows, Lists).

row_to_list(Row, List) :-
    Row =.. [row|List].

read_config(Path) :-
    config_file(ConfigFile),
    open(ConfigFile, read, Stream),
    lerCsvRowList(ConfigFile, [[Path]]),
    close(Stream).

