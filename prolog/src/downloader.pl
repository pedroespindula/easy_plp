:- use_module(library(http/http_open)).

downloader(Exercise, []) :-
    URL = "https://raw.githubusercontent.com/pedroespindula/easy_plp/init-prolog/exercicios/",
    string_concat(URL, Exercise, PartialURL),
    string_concat(PartialURL, ".csv", CompleteURL),
    http_open(CompleteURL, In, []),
    copy_stream_data(In, user_output),
    close(In).

:- initialization
    downloader("dobro", []).