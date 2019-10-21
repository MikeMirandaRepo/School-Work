exactly3(L) :- append([_,_,_|[]],[],L).

at_least_3(L):- append([_,_,_|_],_,L).

at_most_3(L) :- append([],[],L).
at_most_3(L) :- append([_|[]],[],L).
at_most_3(L) :- append([_,_|[]],[],L).
at_most_3(L) :- append([_,_,_|[]],[],L).


intersect(L1,L2) :- member(A,L1), member(A,L2).

all_intersect(L1,L2):- L1 = [A|B],intersect(A,L2), all_intersect(B,L2).
all_intersect([],_).
