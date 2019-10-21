
%For all of these, especially the first two, see the examples in the book
%Ignore the Singleton variable warning, that goes away when you 
% define the rules. 

%europe map coloring problem -- use these colors as the domain
europe_color(Fr,Sw,It,Be,Ho,Ge,Au):- solution(Fr, Sw, It, Be, Ho, Ge, Au).


solution(Fr,Sw,It,Be,Ho,Ge,Au):-
	color(Fr), 
	color(Sw), \+ Fr=Sw,  
	color(It), \+ Fr=It, \+ Sw=It, 
	color(Be), \+ Fr=Be, 
	color(Ho), \+ Be=Ho, 
	color(Ge), \+ Fr=Ge, \+ Sw=Ge, \+ Be=Ge, \+ Ho=Ge,
	color(Au), \+ Sw=Au, \+ It=Au, \+ Ge=Au.

cryptarithmetic(C,R,O,S,A,D,N,G,E):-
	dig(S), dig(S),
	R is (S+S) mod 10, C1 is (S+S) // 10,
	dig(S), dig(D),
	E is (S+D+C1) mod 10, C10 is (S+D+C1) // 10,
	dig(O), dig(A),
	G is (O+A+C10) mod 10, C100 is (O+A+C10) // 10,
	dig(R), dig(O),
	N is (R+O+C100) mod 10, C1000 is (R+O+C100) // 10,
	dig(C), C > 0, dig(R), R > 0,
	A is (C+R+C1000) mod 10, 
	D is (C+R+C1000) // 10,
	uniq_digits(C,R,O,S,A,D,N,G,E).

	uniq_digits(C,R,O,S,A,D,N,G,E):-
	dig(C), dig(R), dig(O), dig(S), dig(A), dig(D), dig(N), dig(G), dig(E),
	\+ C=R, \+ C=O, \+ C=S, \+ C=A, \+ C=D, \+ C=N, \+ C=G, \+ C=E,   
		\+ R=O, \+ R=S, \+ R=A, \+ R=D, \+ R=N, \+ R=G, \+ R=E, 
			\+ O=S, \+ O=A, \+ O=D, \+ O=N, \+ O=G, \+ O=E, 
				\+ S=A, \+ S=D, \+ S=N, \+ S=G, \+ S=E,
					\+ A=D, \+ A=N, \+ A=G, \+ A=E, 
						\+ D=N, \+ D=G, \+ D=E, 
							\+ N=G, \+ N=E, 
								\+ G=E.


%Persons are just their names, lower case
who_ordered_pizza(PizzaPerson):- solution(Donna, Danny, David, Doreen, Steak, Chicken, Coke, Lasagna, Milk, Coffe, Water, Pizza).

	solution(Donna, Danny, David, Doreen, Steak, Chicken, Coke, Lasagna, Milk, Coffee, Water, Pizza):-
	beside(Doreen,Steak),
	Chicken = Coke, 
	across(Lasagna, Milk),
	Donna = Water,
	across(Danny, David),
	across(Doreen, Donna),
	uniq_pos(Steak, Chicken, Lasagna, Pizza),
	uniq_pos(Coke, Milk, Coffee, Water),
	uniq_pos(Donna,Danny, David, Doreen),
	David \= Coffee,
	Danny \= Steak.

	uniq_pos(A,B,C,D):-
	pos(A), pos(B), pos(C), pos(D),
		 \+ A=B, \+ A=C, \+ A=D,
			 \+ B=C, \+ B=D,
				 \+ C=D.
	pos(1). pos(2). pos(3). pos(4).
	beside(A,B):- pos(A), B is (A+1) mod 2.
	across(A,B):- pos(A), B is (A+2) mod 4.













