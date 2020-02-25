import { Component, OnInit } from '@angular/core';
import { Validators, FormBuilder, FormControl, FormGroup } from '@angular/forms';
import { Router } from '@angular/router';

import { ItemService } from '../item.service';


@Component({
  selector: 'app-new-item',
  templateUrl: './new-item.page.html',
  styleUrls: ['./new-item.page.scss'],
})
export class NewItemPage implements OnInit {

  new_item_form: FormGroup;

  constructor(
     private router: Router,
 	 public formBuilder: FormBuilder,
 	     public itemService: ItemService

) { }

  ngOnInit() {

  	this.new_item_form = this.formBuilder.group({
      title: new FormControl('', Validators.required),
      description: new FormControl('', Validators.required),
      BS: new FormControl(false, Validators.required),
      date:new FormControl('', Validators.required)
    });

  }

  createItem(value){
  	console.log(value.title);
  	console.log(value.BS);
  	console.log(value.date);
  	//save the item, and then go back
    //? 
    this.itemService.createItem(value.title,value.description);

  	this.goBack();
  }

  goBack(){
  	    this.router.navigate(['/home']);
  }

}
