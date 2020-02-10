import {
  IonContent,
  IonHeader,
  IonList,
  IonButton,
  IonPage,
  IonTitle,
  IonToolbar,
  IonInput,
  IonItem,
  IonSelect,
  IonLabel,
  IonSelectOption
} from "@ionic/react";
import React, { Component } from "react";
import { setUpNewProducts } from "../../redux/react-redux";
import { connect } from "react-redux";

export interface IAppProps {
  setUpNewProducts: any;
}

export interface IAppState {
  name: string;
  price: number;
  category: string;
  imgURL: string;
  description: string;
}

const mapStateToProps = (state: any) => {
  return {
    products: state.products
  };
};

const mapDispatchToProps = (dispatch: any) => {
  return {
    setUpNewProducts: (order: any) => {
      dispatch(setUpNewProducts(order));
    }
  };
};

class AddProductpage extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    super(props);
    console.log(this.props);
    this.state = {
      name: "",
      price: 0,
      category: "",
      imgURL: "",
      description: ""
    };
  }

  _setUpNewProducts() {
    let newProduct = {
      name: this.state.name,
      price: this.state.price,
      category: this.state.category,
      imgURL: this.state.imgURL,
      description: this.state.description
    };
    console.log(this.state)
    this.props.setUpNewProducts(newProduct);
    alert("You have added an new Product");
  }

  render() {
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Add A Product</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonContent>
          <IonList padding-start>
            <IonInput
              placeholder="Product Name"
              onIonChange={(e: any) => this.setState({ name: e.detail.value })}
            />
            <IonInput
              placeholder="Product Price"
              onIonChange={(e: any) => this.setState({ price: e.detail.value })}
            />
            <IonItem>
              <IonLabel>Category</IonLabel>
              <IonSelect
                placeholder="Select Item Category"
                onIonChange={(e: any) => {
                  this.setState({ category: e.detail.value });
                }}
              >
                <IonSelectOption value="Food">Food</IonSelectOption>
                <IonSelectOption value="Drink">Drink</IonSelectOption>
                <IonSelectOption value="Toy">Toy</IonSelectOption>
                <IonSelectOption value="Apparel">Apparel</IonSelectOption>
              </IonSelect>
            </IonItem>
            <IonInput
              placeholder="Product URL (Optional)"
              onIonChange={(e: any) =>
                this.setState({ imgURL: e.detail.value })
              }
            />
            <IonInput
              placeholder="Product Description"
              onIonChange={(e: any) =>
                this.setState({ description: e.detail.value })
              }
            />
          </IonList>
          <IonButton onClick={() => this._setUpNewProducts()}>
            Add Product
          </IonButton>
        </IonContent>
      </IonPage>
    );
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(AddProductpage);
