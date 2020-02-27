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
import { toast } from "../../components/toast";
import { checkCurrentUser, handleSignOut, getCurrentData } from "../../App";

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
    checkCurrentUser().then((user: any) => {
      if (user) {
        this.setState({ currentUser: user });
        toast(this.state.currentUser.uid);
      }
    });
    super(props);
  }

  componentWillUnmount() {}

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
          <IonCard className="card" key={product.id}>
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
              onClick={() => handleSignOut()}
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
        <IonContent>
          <IonButton onClick={() => checkCurrentUser()}>Check User</IonButton>
          <IonButton onClick={() => getCurrentData("products")}>
            Get User Products
          </IonButton>
          <IonButton onClick={() => getCurrentData("orders")}>
            Get User Orders
          </IonButton>

          {productCards}
        </IonContent>
      </IonPage>
    );
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(ProductListPage);
