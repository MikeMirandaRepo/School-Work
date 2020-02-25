import { Component,OnInit } from '@angular/core';
import { Router } from '@angular/router';

import { ItemService } from '../item.service';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage implements OnInit {

  imgfile="assets/icecream.jpg";
  
  items=[
    {"title":"meat","description":"good",'img':this.imgfile},
    {"title":"meat2","description":"good","img":"assets/meat.jpg"},
    {"title":"meat3","description":"good","img":"assets/icecream.jpg"}
  ]

  constructor(
    private router: Router,
    public itemService: ItemService

  ){}

  ngOnInit(){
    this.items = this.itemService.getItems();
    console.log(this.items.length);
    // this.itemService.createItem("dd","dds");
  }

  openNewItemPage(){
  	console.log("clicked me");
  	this.router.navigate(["/new-item"]);

	}

goToItem(item){
  	console.log(item);
  	this.router.navigate(["/update-item", item]);

  }
  
}
