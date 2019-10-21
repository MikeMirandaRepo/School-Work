
:-['Pr4.pl'].


lists([]).
lists([a]).
lists([c,b]).
lists([b,c]).
lists([a,c]).
lists([a,b]).
lists([c,b,a]).
lists([b,c,b]).
lists([a,c,c]).
lists([a,b,d]).
lists([c,b,d,b]).
lists([b,c,c,a]).
lists([a,c,b,c]).
lists([a,b,a,d]).
lists([a,c,a,a]).
lists(L):-listsA(L).

%all_intersect tests explode... so listsA is just a fraction of lists

listsA([d]).
listsA([c,b]).
listsA([b,a]).
listsA([a,c,a]).
listsA([b,a,a]).
listsA([b,a,b,d]).

score(S):-
	testQ6a(Sa),write('Score Q6(a) is:'),write(Sa),nl,
	testQ6b(Sb),write('Score Q6(b) is:'),write(Sb),nl,
	testQ6c(Sc),write('Score Q6(c) is:'),write(Sc),nl,
	testQ6d(Sd),write('Score Q6(d) is:'),write(Sd),nl,
	testQ6e(Se),write('Score Q6(e) is:'),write(Se),nl,
	S is Sa+Sb+Sc+Sd+Se,
	write('TOTAL SCORE = '),write(S),nl.






testExactly3(L):-lists(L),exactly3(L).
testQ6a(S):-findall([L],testExactly3(L),LL),
	                 TRUEs= [[[a,b,d]],[[a,c,a]],[[a,c,c]],[[b,a,a]],[[b,c,b]],[[c,b,a]]],
			 sort(LL,SLL),
			 ((SLL=TRUEs,S is 20) ; (\+ SLL = TRUEs,S is 0)).


testAt_least_3(L):-lists(L),at_least_3(L).
testQ6b(S):-findall([L],testAt_least_3(L),LL),
	                 TRUEs= [[[a,b,a,d]],[[a,b,d]],[[a,c,a]],[[a,c,a,a]],[[a,c,b,c]],[[a,c,c]],[[b,a,a]],[[b,a,b,d]],[[b,c,b]],[[b,c,c,a]],[[c,b,a]],[[c,b,d,b]]],
			 sort(LL,SLL),
			 ((SLL=TRUEs,S is 20) ; (\+ SLL = TRUEs,S is 0)).

testAt_most_3(L):-lists(L),at_most_3(L).
testQ6c(S):-findall([L],testAt_most_3(L),LL),
	                 TRUEs=  [[[]],[[a]],[[a,b]],[[a,b,d]],[[a,c]],[[a,c,a]],[[a,c,c]],[[b,a]],[[b,a,a]],[[b,c]],[[b,c,b]],[[c,b]],[[c,b,a]],[[d]]],
			 sort(LL,SLL),
			 ((SLL=TRUEs,S is 20) ; (\+ SLL = TRUEs,S is 0)).


testIntersect(L1,L2):-lists(L1),lists(L2),intersect(L1,L2).
testQ6d(S):-findall([L1,L2],testIntersect(L1,L2),LL),
	                 TRUEs=[[[a],[a]],[[a],[a,b]],[[a],[a,b,a,d]],[[a],[a,b,d]],[[a],[a,c]],[[a],[a,c,a]],[[a],[a,c,a,a]],[[a],[a,c,b,c]],[[a],[a,c,c]],[[a],[b,a]],[[a],[b,a,a]],[[a],[b,a,b,d]],[[a],[b,c,c,a]],[[a],[c,b,a]],[[a,b],[a]],[[a,b],[a,b]],[[a,b],[a,b,a,d]],[[a,b],[a,b,d]],[[a,b],[a,c]],[[a,b],[a,c,a]],[[a,b],[a,c,a,a]],[[a,b],[a,c,b,c]],[[a,b],[a,c,c]],[[a,b],[b,a]],[[a,b],[b,a,a]],[[a,b],[b,a,b,d]],[[a,b],[b,c]],[[a,b],[b,c,b]],[[a,b],[b,c,c,a]],[[a,b],[c,b]],[[a,b],[c,b,a]],[[a,b],[c,b,d,b]],[[a,b,a,d],[a]],[[a,b,a,d],[a,b]],[[a,b,a,d],[a,b,a,d]],[[a,b,a,d],[a,b,d]],[[a,b,a,d],[a,c]],[[a,b,a,d],[a,c,a]],[[a,b,a,d],[a,c,a,a]],[[a,b,a,d],[a,c,b,c]],[[a,b,a,d],[a,c,c]],[[a,b,a,d],[b,a]],[[a,b,a,d],[b,a,a]],[[a,b,a,d],[b,a,b,d]],[[a,b,a,d],[b,c]],[[a,b,a,d],[b,c,b]],[[a,b,a,d],[b,c,c,a]],[[a,b,a,d],[c,b]],[[a,b,a,d],[c,b,a]],[[a,b,a,d],[c,b,d,b]],[[a,b,a,d],[d]],[[a,b,d],[a]],[[a,b,d],[a,b]],[[a,b,d],[a,b,a,d]],[[a,b,d],[a,b,d]],[[a,b,d],[a,c]],[[a,b,d],[a,c,a]],[[a,b,d],[a,c,a,a]],[[a,b,d],[a,c,b,c]],[[a,b,d],[a,c,c]],[[a,b,d],[b,a]],[[a,b,d],[b,a,a]],[[a,b,d],[b,a,b,d]],[[a,b,d],[b,c]],[[a,b,d],[b,c,b]],[[a,b,d],[b,c,c,a]],[[a,b,d],[c,b]],[[a,b,d],[c,b,a]],[[a,b,d],[c,b,d,b]],[[a,b,d],[d]],[[a,c],[a]],[[a,c],[a,b]],[[a,c],[a,b,a,d]],[[a,c],[a,b,d]],[[a,c],[a,c]],[[a,c],[a,c,a]],[[a,c],[a,c,a,a]],[[a,c],[a,c,b,c]],[[a,c],[a,c,c]],[[a,c],[b,a]],[[a,c],[b,a,a]],[[a,c],[b,a,b,d]],[[a,c],[b,c]],[[a,c],[b,c,b]],[[a,c],[b,c,c,a]],[[a,c],[c,b]],[[a,c],[c,b,a]],[[a,c],[c,b,d,b]],[[a,c,a],[a]],[[a,c,a],[a,b]],[[a,c,a],[a,b,a,d]],[[a,c,a],[a,b,d]],[[a,c,a],[a,c]],[[a,c,a],[a,c,a]],[[a,c,a],[a,c,a,a]],[[a,c,a],[a,c,b,c]],[[a,c,a],[a,c,c]],[[a,c,a],[b,a]],[[a,c,a],[b,a,a]],[[a,c,a],[b,a,b,d]],[[a,c,a],[b,c]],[[a,c,a],[b,c,b]],[[a,c,a],[b,c,c,a]],[[a,c,a],[c,b]],[[a,c,a],[c,b,a]],[[a,c,a],[c,b,d,b]],[[a,c,a,a],[a]],[[a,c,a,a],[a,b]],[[a,c,a,a],[a,b,a,d]],[[a,c,a,a],[a,b,d]],[[a,c,a,a],[a,c]],[[a,c,a,a],[a,c,a]],[[a,c,a,a],[a,c,a,a]],[[a,c,a,a],[a,c,b,c]],[[a,c,a,a],[a,c,c]],[[a,c,a,a],[b,a]],[[a,c,a,a],[b,a,a]],[[a,c,a,a],[b,a,b,d]],[[a,c,a,a],[b,c]],[[a,c,a,a],[b,c,b]],[[a,c,a,a],[b,c,c,a]],[[a,c,a,a],[c,b]],[[a,c,a,a],[c,b,a]],[[a,c,a,a],[c,b,d,b]],[[a,c,b,c],[a]],[[a,c,b,c],[a,b]],[[a,c,b,c],[a,b,a,d]],[[a,c,b,c],[a,b,d]],[[a,c,b,c],[a,c]],[[a,c,b,c],[a,c,a]],[[a,c,b,c],[a,c,a,a]],[[a,c,b,c],[a,c,b,c]],[[a,c,b,c],[a,c,c]],[[a,c,b,c],[b,a]],[[a,c,b,c],[b,a,a]],[[a,c,b,c],[b,a,b,d]],[[a,c,b,c],[b,c]],[[a,c,b,c],[b,c,b]],[[a,c,b,c],[b,c,c,a]],[[a,c,b,c],[c,b]],[[a,c,b,c],[c,b,a]],[[a,c,b,c],[c,b,d,b]],[[a,c,c],[a]],[[a,c,c],[a,b]],[[a,c,c],[a,b,a,d]],[[a,c,c],[a,b,d]],[[a,c,c],[a,c]],[[a,c,c],[a,c,a]],[[a,c,c],[a,c,a,a]],[[a,c,c],[a,c,b,c]],[[a,c,c],[a,c,c]],[[a,c,c],[b,a]],[[a,c,c],[b,a,a]],[[a,c,c],[b,a,b,d]],[[a,c,c],[b,c]],[[a,c,c],[b,c,b]],[[a,c,c],[b,c,c,a]],[[a,c,c],[c,b]],[[a,c,c],[c,b,a]],[[a,c,c],[c,b,d,b]],[[b,a],[a]],[[b,a],[a,b]],[[b,a],[a,b,a,d]],[[b,a],[a,b,d]],[[b,a],[a,c]],[[b,a],[a,c,a]],[[b,a],[a,c,a,a]],[[b,a],[a,c,b,c]],[[b,a],[a,c,c]],[[b,a],[b,a]],[[b,a],[b,a,a]],[[b,a],[b,a,b,d]],[[b,a],[b,c]],[[b,a],[b,c,b]],[[b,a],[b,c,c,a]],[[b,a],[c,b]],[[b,a],[c,b,a]],[[b,a],[c,b,d,b]],[[b,a,a],[a]],[[b,a,a],[a,b]],[[b,a,a],[a,b,a,d]],[[b,a,a],[a,b,d]],[[b,a,a],[a,c]],[[b,a,a],[a,c,a]],[[b,a,a],[a,c,a,a]],[[b,a,a],[a,c,b,c]],[[b,a,a],[a,c,c]],[[b,a,a],[b,a]],[[b,a,a],[b,a,a]],[[b,a,a],[b,a,b,d]],[[b,a,a],[b,c]],[[b,a,a],[b,c,b]],[[b,a,a],[b,c,c,a]],[[b,a,a],[c,b]],[[b,a,a],[c,b,a]],[[b,a,a],[c,b,d,b]],[[b,a,b,d],[a]],[[b,a,b,d],[a,b]],[[b,a,b,d],[a,b,a,d]],[[b,a,b,d],[a,b,d]],[[b,a,b,d],[a,c]],[[b,a,b,d],[a,c,a]],[[b,a,b,d],[a,c,a,a]],[[b,a,b,d],[a,c,b,c]],[[b,a,b,d],[a,c,c]],[[b,a,b,d],[b,a]],[[b,a,b,d],[b,a,a]],[[b,a,b,d],[b,a,b,d]],[[b,a,b,d],[b,c]],[[b,a,b,d],[b,c,b]],[[b,a,b,d],[b,c,c,a]],[[b,a,b,d],[c,b]],[[b,a,b,d],[c,b,a]],[[b,a,b,d],[c,b,d,b]],[[b,a,b,d],[d]],[[b,c],[a,b]],[[b,c],[a,b,a,d]],[[b,c],[a,b,d]],[[b,c],[a,c]],[[b,c],[a,c,a]],[[b,c],[a,c,a,a]],[[b,c],[a,c,b,c]],[[b,c],[a,c,c]],[[b,c],[b,a]],[[b,c],[b,a,a]],[[b,c],[b,a,b,d]],[[b,c],[b,c]],[[b,c],[b,c,b]],[[b,c],[b,c,c,a]],[[b,c],[c,b]],[[b,c],[c,b,a]],[[b,c],[c,b,d,b]],[[b,c,b],[a,b]],[[b,c,b],[a,b,a,d]],[[b,c,b],[a,b,d]],[[b,c,b],[a,c]],[[b,c,b],[a,c,a]],[[b,c,b],[a,c,a,a]],[[b,c,b],[a,c,b,c]],[[b,c,b],[a,c,c]],[[b,c,b],[b,a]],[[b,c,b],[b,a,a]],[[b,c,b],[b,a,b,d]],[[b,c,b],[b,c]],[[b,c,b],[b,c,b]],[[b,c,b],[b,c,c,a]],[[b,c,b],[c,b]],[[b,c,b],[c,b,a]],[[b,c,b],[c,b,d,b]],[[b,c,c,a],[a]],[[b,c,c,a],[a,b]],[[b,c,c,a],[a,b,a,d]],[[b,c,c,a],[a,b,d]],[[b,c,c,a],[a,c]],[[b,c,c,a],[a,c,a]],[[b,c,c,a],[a,c,a,a]],[[b,c,c,a],[a,c,b,c]],[[b,c,c,a],[a,c,c]],[[b,c,c,a],[b,a]],[[b,c,c,a],[b,a,a]],[[b,c,c,a],[b,a,b,d]],[[b,c,c,a],[b,c]],[[b,c,c,a],[b,c,b]],[[b,c,c,a],[b,c,c,a]],[[b,c,c,a],[c,b]],[[b,c,c,a],[c,b,a]],[[b,c,c,a],[c,b,d,b]],[[c,b],[a,b]],[[c,b],[a,b,a,d]],[[c,b],[a,b,d]],[[c,b],[a,c]],[[c,b],[a,c,a]],[[c,b],[a,c,a,a]],[[c,b],[a,c,b,c]],[[c,b],[a,c,c]],[[c,b],[b,a]],[[c,b],[b,a,a]],[[c,b],[b,a,b,d]],[[c,b],[b,c]],[[c,b],[b,c,b]],[[c,b],[b,c,c,a]],[[c,b],[c,b]],[[c,b],[c,b,a]],[[c,b],[c,b,d,b]],[[c,b,a],[a]],[[c,b,a],[a,b]],[[c,b,a],[a,b,a,d]],[[c,b,a],[a,b,d]],[[c,b,a],[a,c]],[[c,b,a],[a,c,a]],[[c,b,a],[a,c,a,a]],[[c,b,a],[a,c,b,c]],[[c,b,a],[a,c,c]],[[c,b,a],[b,a]],[[c,b,a],[b,a,a]],[[c,b,a],[b,a,b,d]],[[c,b,a],[b,c]],[[c,b,a],[b,c,b]],[[c,b,a],[b,c,c,a]],[[c,b,a],[c,b]],[[c,b,a],[c,b,a]],[[c,b,a],[c,b,d,b]],[[c,b,d,b],[a,b]],[[c,b,d,b],[a,b,a,d]],[[c,b,d,b],[a,b,d]],[[c,b,d,b],[a,c]],[[c,b,d,b],[a,c,a]],[[c,b,d,b],[a,c,a,a]],[[c,b,d,b],[a,c,b,c]],[[c,b,d,b],[a,c,c]],[[c,b,d,b],[b,a]],[[c,b,d,b],[b,a,a]],[[c,b,d,b],[b,a,b,d]],[[c,b,d,b],[b,c]],[[c,b,d,b],[b,c,b]],[[c,b,d,b],[b,c,c,a]],[[c,b,d,b],[c,b]],[[c,b,d,b],[c,b,a]],[[c,b,d,b],[c,b,d,b]],[[c,b,d,b],[d]],[[d],[a,b,a,d]],[[d],[a,b,d]],[[d],[b,a,b,d]],[[d],[c,b,d,b]],[[d],[d]]],
			 sort(LL,SLL),
			 ((SLL=TRUEs,S is 20) ; (\+ SLL = TRUEs,S is 0)).



testAll_intersect(L1,L2,L3):-listsA(L1),listsA(L2),listsA(L3),all_intersect([L1,L2],L3).
testQ6e(S):-findall([L1,L2,L3],testAll_intersect(L1,L2,L3),LL),
	                 TRUEs=  [[[a,c,a],[a,c,a],[a,c,a]],[[a,c,a],[a,c,a],[b,a]],[[a,c,a],[a,c,a],[b,a,a]],[[a,c,a],[a,c,a],[b,a,b,d]],[[a,c,a],[a,c,a],[c,b]],[[a,c,a],[b,a],[a,c,a]],[[a,c,a],[b,a],[b,a]],[[a,c,a],[b,a],[b,a,a]],[[a,c,a],[b,a],[b,a,b,d]],[[a,c,a],[b,a],[c,b]],[[a,c,a],[b,a,a],[a,c,a]],[[a,c,a],[b,a,a],[b,a]],[[a,c,a],[b,a,a],[b,a,a]],[[a,c,a],[b,a,a],[b,a,b,d]],[[a,c,a],[b,a,a],[c,b]],[[a,c,a],[b,a,b,d],[a,c,a]],[[a,c,a],[b,a,b,d],[b,a]],[[a,c,a],[b,a,b,d],[b,a,a]],[[a,c,a],[b,a,b,d],[b,a,b,d]],[[a,c,a],[b,a,b,d],[c,b]],[[a,c,a],[c,b],[a,c,a]],[[a,c,a],[c,b],[b,a]],[[a,c,a],[c,b],[b,a,a]],[[a,c,a],[c,b],[b,a,b,d]],[[a,c,a],[c,b],[c,b]],[[a,c,a],[d],[b,a,b,d]],[[b,a],[a,c,a],[a,c,a]],[[b,a],[a,c,a],[b,a]],[[b,a],[a,c,a],[b,a,a]],[[b,a],[a,c,a],[b,a,b,d]],[[b,a],[a,c,a],[c,b]],[[b,a],[b,a],[a,c,a]],[[b,a],[b,a],[b,a]],[[b,a],[b,a],[b,a,a]],[[b,a],[b,a],[b,a,b,d]],[[b,a],[b,a],[c,b]],[[b,a],[b,a,a],[a,c,a]],[[b,a],[b,a,a],[b,a]],[[b,a],[b,a,a],[b,a,a]],[[b,a],[b,a,a],[b,a,b,d]],[[b,a],[b,a,a],[c,b]],[[b,a],[b,a,b,d],[a,c,a]],[[b,a],[b,a,b,d],[b,a]],[[b,a],[b,a,b,d],[b,a,a]],[[b,a],[b,a,b,d],[b,a,b,d]],[[b,a],[b,a,b,d],[c,b]],[[b,a],[c,b],[a,c,a]],[[b,a],[c,b],[b,a]],[[b,a],[c,b],[b,a,a]],[[b,a],[c,b],[b,a,b,d]],[[b,a],[c,b],[c,b]],[[b,a],[d],[b,a,b,d]],[[b,a,a],[a,c,a],[a,c,a]],[[b,a,a],[a,c,a],[b,a]],[[b,a,a],[a,c,a],[b,a,a]],[[b,a,a],[a,c,a],[b,a,b,d]],[[b,a,a],[a,c,a],[c,b]],[[b,a,a],[b,a],[a,c,a]],[[b,a,a],[b,a],[b,a]],[[b,a,a],[b,a],[b,a,a]],[[b,a,a],[b,a],[b,a,b,d]],[[b,a,a],[b,a],[c,b]],[[b,a,a],[b,a,a],[a,c,a]],[[b,a,a],[b,a,a],[b,a]],[[b,a,a],[b,a,a],[b,a,a]],[[b,a,a],[b,a,a],[b,a,b,d]],[[b,a,a],[b,a,a],[c,b]],[[b,a,a],[b,a,b,d],[a,c,a]],[[b,a,a],[b,a,b,d],[b,a]],[[b,a,a],[b,a,b,d],[b,a,a]],[[b,a,a],[b,a,b,d],[b,a,b,d]],[[b,a,a],[b,a,b,d],[c,b]],[[b,a,a],[c,b],[a,c,a]],[[b,a,a],[c,b],[b,a]],[[b,a,a],[c,b],[b,a,a]],[[b,a,a],[c,b],[b,a,b,d]],[[b,a,a],[c,b],[c,b]],[[b,a,a],[d],[b,a,b,d]],[[b,a,b,d],[a,c,a],[a,c,a]],[[b,a,b,d],[a,c,a],[b,a]],[[b,a,b,d],[a,c,a],[b,a,a]],[[b,a,b,d],[a,c,a],[b,a,b,d]],[[b,a,b,d],[a,c,a],[c,b]],[[b,a,b,d],[b,a],[a,c,a]],[[b,a,b,d],[b,a],[b,a]],[[b,a,b,d],[b,a],[b,a,a]],[[b,a,b,d],[b,a],[b,a,b,d]],[[b,a,b,d],[b,a],[c,b]],[[b,a,b,d],[b,a,a],[a,c,a]],[[b,a,b,d],[b,a,a],[b,a]],[[b,a,b,d],[b,a,a],[b,a,a]],[[b,a,b,d],[b,a,a],[b,a,b,d]],[[b,a,b,d],[b,a,a],[c,b]],[[b,a,b,d],[b,a,b,d],[a,c,a]],[[b,a,b,d],[b,a,b,d],[b,a]],[[b,a,b,d],[b,a,b,d],[b,a,a]],[[b,a,b,d],[b,a,b,d],[b,a,b,d]],[[b,a,b,d],[b,a,b,d],[c,b]],[[b,a,b,d],[b,a,b,d],[d]],[[b,a,b,d],[c,b],[a,c,a]],[[b,a,b,d],[c,b],[b,a]],[[b,a,b,d],[c,b],[b,a,a]],[[b,a,b,d],[c,b],[b,a,b,d]],[[b,a,b,d],[c,b],[c,b]],[[b,a,b,d],[d],[b,a,b,d]],[[b,a,b,d],[d],[d]],[[c,b],[a,c,a],[a,c,a]],[[c,b],[a,c,a],[b,a]],[[c,b],[a,c,a],[b,a,a]],[[c,b],[a,c,a],[b,a,b,d]],[[c,b],[a,c,a],[c,b]],[[c,b],[b,a],[a,c,a]],[[c,b],[b,a],[b,a]],[[c,b],[b,a],[b,a,a]],[[c,b],[b,a],[b,a,b,d]],[[c,b],[b,a],[c,b]],[[c,b],[b,a,a],[a,c,a]],[[c,b],[b,a,a],[b,a]],[[c,b],[b,a,a],[b,a,a]],[[c,b],[b,a,a],[b,a,b,d]],[[c,b],[b,a,a],[c,b]],[[c,b],[b,a,b,d],[a,c,a]],[[c,b],[b,a,b,d],[b,a]],[[c,b],[b,a,b,d],[b,a,a]],[[c,b],[b,a,b,d],[b,a,b,d]],[[c,b],[b,a,b,d],[c,b]],[[c,b],[c,b],[a,c,a]],[[c,b],[c,b],[b,a]],[[c,b],[c,b],[b,a,a]],[[c,b],[c,b],[b,a,b,d]],[[c,b],[c,b],[c,b]],[[c,b],[d],[b,a,b,d]],[[d],[a,c,a],[b,a,b,d]],[[d],[b,a],[b,a,b,d]],[[d],[b,a,a],[b,a,b,d]],[[d],[b,a,b,d],[b,a,b,d]],[[d],[b,a,b,d],[d]],[[d],[c,b],[b,a,b,d]],[[d],[d],[b,a,b,d]],[[d],[d],[d]]],
			 sort(LL,SLL),
			 ((SLL=TRUEs,S is 20) ; (\+ SLL = TRUEs,S is 0)).


:-score(S),nl,write('Score = '),write(S).
