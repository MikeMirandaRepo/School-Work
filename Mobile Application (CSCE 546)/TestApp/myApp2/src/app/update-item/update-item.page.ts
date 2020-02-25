import { Component, OnInit } from '@angular/core';

import { Validators, FormBuilder, FormControl, FormGroup } from '@angular/forms';
import { Router,ActivatedRoute } from '@angular/router';

import { ItemService } from '../item.service';


@Component({
  selector: 'app-update-item',
  templateUrl: './update-item.page.html',
  styleUrls: ['./update-item.page.scss'],
})
export class UpdateItemPage implements OnInit {

  current_item:any;
  edit_item_form:FormGroup;
  constructor(
    public formBuilder: FormBuilder,
    private route: ActivatedRoute,
    private itemService: ItemService,
    private router:Router
  	) { 
  		this.edit_item_form = this.formBuilder.group({
          title: new FormControl("", Validators.required),
          description: new FormControl("", Validators.required),
        });
        console.log("constructor of UpdateItemPage")
  }

  ngOnInit() {
  		console.log("onInit")
  		this.route.params.subscribe(
      param => {
        this.current_item = param;
        console.log(this.current_item);

        this.edit_item_form.patchValue({title:this.current_item.title});
        this.edit_item_form.patchValue({description:this.current_item.description});

      }
    )
  }

  updateItem(value){
  	console.log(value.title);
  	console.log(value.description);

  	//update the item in the items of th Service Object
  	//need to import the ItemService and create it in constructor
  	let newValues = {
      id: this.current_item.id,
      title: value.title,
      description: value.description
    }
    this.itemService.updateItem(newValues);


    this.goBack();
  }

  goBack(){
    this.router.navigate(['/home']);
  }

}
