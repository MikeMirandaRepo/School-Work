const seq1:string = "GAGCCTACTAACGGGAT";
const seq2:string = "CATCGTAATGACGGCCT";

function align(seq1:string, seq2:string) : number{
	let same:number = 0;
	for(let i:number = 0; i < seq1.length; i++){
		//console.log(seq1[i]);
		//console.log(seq2[i]);
		if(seq1[i] == seq2[i])
			same++;
	}
	console.log(same);
	return same;
}


//align(seq1, seq2);

var arrowAlign = (seq1:string, seq2:string)  : number => {
	let same:number = 0;
	for(let i:number = 0; i < seq1.length; i++){
		if(seq1[i] == seq2[i])
			same++;
	}
	console.log(same);
	return same;
}
//arrowAlign(seq1, seq2);


export class alignClass {
	seq1Class: string;
	seq2Class: string;
	same: number;

	constructor(seq1Class:string, seq2Class: string){
		this.same = 0;
		this.seq1Class = seq1Class;
        this.seq2Class = seq2Class;

		for(let i:number = 0; i < this.seq2Class.length; i++){
			if(seq1Class[i] == seq2Class[i])
				this.same++;
	}
	console.log(this.same);
		
	}
}
var data = new alignClass(seq1, seq2);
let seq1Data:string = data.seq1Class;
//console.log(seq1Data);