import {
  IonCardHeader,
  IonCardSubtitle,
  IonCardTitle,
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonCard
} from "@ionic/react";
import React from "react";
import { Link } from "react-router-dom";
import { connect } from "react-redux";

export interface IAppProps {
  orders: [];
}

export interface IAppState {}

const mapStateToProps = (state: any) => {
  return {
    orders: state.orders
  };
};

const mapDispatchToProps = (dispatch: any) => {
  return {};
};


class OrderListPage extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    super(props);
    console.log(this.props);
    this.state = {};
  }

  _createCardList(orders: []) {
    return orders.map((order: any) => {
      return (
        <Link
          to={{
            pathname: "/OrderDetailList/OrderDetailPage",
            state: { order: order }
          }}
        >
          <IonCard className="card">
            <IonCardHeader>
              <IonCardTitle>Order ID: {order.orderID}</IonCardTitle>
              <IonCardSubtitle>Date Ordered: {order.orderDate}</IonCardSubtitle>
              <IonCardSubtitle>Order Count:{order.numItems}</IonCardSubtitle>
              <IonCardSubtitle>Total Price: {order.totalPrice}</IonCardSubtitle>
            </IonCardHeader>
          </IonCard>
        </Link>
      );
    });
  }

  render() {
    let orderCards: any = this._createCardList(this.props.orders);
    console.log(orderCards);

    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Order List</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonContent>
          {orderCards}
        </IonContent>
      </IonPage>
    );
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(OrderListPage);
