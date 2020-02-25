import {
  IonCard,
  IonCardHeader,
  IonCardSubtitle,
  IonCardTitle,
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonText,
  IonButton
} from "@ionic/react";
import { connect } from "react-redux";
import { Link } from "react-router-dom";
import React, { Component } from "react";
import firebase from "firebase";
import { wait } from "@testing-library/react";
//import Product from "../components";
const imgURLDefault: string =
  "https://www.foragegroup.com/public/images/noim.png";

const mapStateToProps = (state: any) => {
  return {
    products: state.products
  };
};

const mapDispatchToProps = (dispatch: any) => {
  return {};
};

export interface IAppProps {
  products: [];
}

export interface IAppState {
  currentUser: any;
}

class ProductListPage extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    super(props);
    this.state = { currentUser: null };
  }
  componentDidMount() {
    firebase.auth().onAuthStateChanged(user => {
      if (user) {
        const { currentUser } = firebase.auth();
        this.setState({ currentUser });
        console.log(this.state.currentUser.uid);
      }
    });
  }
  _createCardList(products: []) {
    return products.map((product: any) => {
      return (
        <Link
          to={{
            pathname: "/ProductListPage/ProductDetailPage",
            state: { product: product }
          }}
          style={{ textDecoration: "none" }}
        >
          <IonCard className="card">
            <IonCardHeader>
              <IonCardTitle>{product.name}</IonCardTitle>
              <IonCardSubtitle>
                <IonText>Price: $</IonText>
                {product.price}
              </IonCardSubtitle>
              <IonCardSubtitle>{product.category} </IonCardSubtitle>
            </IonCardHeader>

            <img src={product.imgURL} />
            <IonText>Description: {product.description}</IonText>
          </IonCard>
        </Link>
      );
    });
  }
  public render() {
    let productCards: any = this._createCardList(this.props.products);
    //console.log(productCards);
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Products</IonTitle>
            <IonButton
              onClick={() => firebase.auth().signOut()}
              slot="start"
              routerDirection="back"
              routerLink="/Login"
            >
              Log Out
            </IonButton>
            <IonButton slot="end" routerLink="/ProductListPage/AddProductPage">
              <IonText>Add Product</IonText>
            </IonButton>
          </IonToolbar>
        </IonHeader>
        <IonContent>{productCards}</IonContent>
      </IonPage>
    );
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(ProductListPage);
