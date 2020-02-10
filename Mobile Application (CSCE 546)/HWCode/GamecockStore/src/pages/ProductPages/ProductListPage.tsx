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

export interface IAppState {}

class ProductListPage extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    super(props);
    this.state = {};
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
    console.log(productCards);
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Products</IonTitle>
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

// const mapStateToProps = (state: any) => {
//   return {
//     products: state.products
//   };
// };

// const mapDispatchToProps = (dispatch: any) => {
//   return {};
// };

// export interface IAppProps {
//   products: [];
// }

// export interface IAppState {}

// class ProductListPage extends React.Component<IAppProps, IAppState> {
//   constructor(props: IAppProps) {
//     super(props);
//     this.state = {};
//   }

//   _createCardList(products: []) {
//     return products.map((product: any) => {
//       return (
//         <Link
//           to={{ pathname: "/ProductDetailsPage", state: { product: product } }}
//           style={{ textDecoration: "none" }}
//         >
//           <IonCard className="card">
//             <IonCardHeader>
//               <IonCardTitle>{product.name}</IonCardTitle>
//               <IonCardSubtitle>
//                 <IonText>Price: </IonText>
//                 {product.price}
//               </IonCardSubtitle>
//             </IonCardHeader>
//             <IonGrid>
//               <IonRow>
//                 <IonCol>
//                   <img className="col-33" src={product.photo_url} />
//                 </IonCol>
//                 <IonCol>
//                   <IonRow>
//                     <IonText>Type: {product.category}</IonText>
//                   </IonRow>
//                   <IonRow>
//                     <IonText>Description: {product.description}</IonText>
//                   </IonRow>
//                 </IonCol>
//               </IonRow>
//             </IonGrid>
//           </IonCard>
//         </Link>
//       );
//     });
//   }

//   public render() {
//     let Cards: any =
//       this.props.products.length > 0
//         ? this._createCardList(this.props.products)
//         : null;
//     console.log(Cards);
//     return (
//       <IonPage>
//         <IonHeader>
//           <IonToolbar>
//             <IonTitle>Products</IonTitle>
//           </IonToolbar>
//         </IonHeader>
//         <IonContent>{Cards}</IonContent>
//       </IonPage>
//     );
//   }
// }

// export default connect(mapStateToProps, mapDispatchToProps)(ProductListPage);

// render() {
//   return (
//     <IonPage>
//       <IonHeader>
//         <IonToolbar>
//           <IonTitle>Product List</IonTitle>
//           <Link slot="primary" to="/ProductListPage/AddProductPage">
//             {" "}
//             <IonButton slot="primary">Add</IonButton>
//           </Link>
//         </IonToolbar>
//       </IonHeader>
//       <IonContent>
//         <IonList class="ion-text-center">
//           {products.map((element, i) => (
//             <Link
//               to={{
//                 pathname: "/ProductListPage/ProductDetailPage",
//                 state: {
//                   count: 1,
//                   totalCost: element.price,
//                   price: element.price,
//                   name: element.name,
//                   category: element.category,
//                   imgURL: element.imgURL
//                 }
//               }}
//             >
//               {console.log(element.imgURL)}
//               <IonItemSliding key={element.imgURL}>
//                 <IonCard>
//                   <IonCardHeader>
//                     <IonCardSubtitle>{element.category} </IonCardSubtitle>
//                     <IonCardTitle>{element.name} </IonCardTitle>
//                   </IonCardHeader>
//                   <img src={element.imgURL} />
//                 </IonCard>
//               </IonItemSliding>
//             </Link>
//           ))}
//         </IonList>
//       </IonContent>
//     </IonPage>
//   );
// }
