import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class ItemService {

  //define some data containers such as arrays to store items
  items:Array<any>=[{"id":1,"title":"meat2","description":"good","img":"assets/meat.jpg"}];

  constructor() { }

  //provide functions to get items, and save items

  getItems(){
  	return this.items;
  }

  createItem(title,description){
  	  let randomId = Math.random().toString(36).substr(2, 5);
    this.items.push({
      'id': randomId,
      'title': title,
      'description': description,
      'img':"assets/meat.jpg"
    });
  }

  updateItem(newValues){
    let itemIndex = this.items.findIndex(item => item.id == newValues.id);
    
    if(newValues.img == undefined){
    	newValues.img = this.items[itemIndex].img
    }

    this.items[itemIndex] = newValues;
    console.log(newValues.img);
  }


}
