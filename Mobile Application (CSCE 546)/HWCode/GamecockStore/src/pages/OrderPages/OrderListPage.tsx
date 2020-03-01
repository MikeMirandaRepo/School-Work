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
import { watchOrders } from "../../redux/react-redux";
import { returnUserUID } from "../../App";
const mapStateToProps = (state: any) => {
  return {
    orders: state.ordersF
  };
};

const mapDispatchToProps = (dispatch: any) => {
  return {
    watchOrders: () => {
      console.log(returnUserUID())
      dispatch(watchOrders(returnUserUID()));
    }
  };
};

export interface IAppProps {
  orders: [];
  watchOrders: any;
}

export interface IAppState {}

class OrderListPage extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    super(props);
    this.state = {};
    this.props.watchOrders();
  }

  _createCardList(orders: []) {
    return orders.map((order: any, index:any) => {
      return (
        <Link
          to={{
            pathname: "/OrderDetailList/OrderDetailPage",
            state: { order: order }
          }}
        >
          <IonCard className="card" key={index}>
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
    //console.log(orderCards);

    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Order List</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonContent>{orderCards}</IonContent>
      </IonPage>
    );
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(OrderListPage);
