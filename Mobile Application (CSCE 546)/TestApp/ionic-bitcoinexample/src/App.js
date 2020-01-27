import React, {Component} from 'react';
import logo from './logo.svg';
import './App.css';
import {IonApp, IonHeader, IonToolbar, IonTitle, IonContent, IonText} from '@ionic/react'
import { getBitcoinPrice } from './api/bitcoin';
import LoadingCard from './components/LoadingCard'
import BitCoinCard from './components/BitCoinCard'


class App extends Component {
  state = {
    bitCoinInfo: {},
    loading: false,
  };

  async componentDidMount(){
    const bitCoinInfo = await getBitcoinPrice('CNY');

    this.setState({
      bitCoinInfo,
      loading: true,
    })
  }


  createLoadingCards() {
    return(
    <>
      <LoadingCard/>
      <LoadingCard/>
      <LoadingCard/>
    </>
    );
  } 




render(){
  const {bitCoinInfo, loading} = this.state;
  console.log(bitCoinInfo.bpi, loading)
  return(
    <IonApp>
      <IonHeader>
        <IonToolbar color="primary">
  <IonTitle align="center">BitCoin Price Tracker</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent>
        {
        loading === true ?
        Object.keys(bitCoinInfo.bpi)
        .map((item, index) => 
        <BitCoinCard data = {bitCoinInfo.bpi[item]}/>) 
        : null
        }
      </IonContent>
    </IonApp>

    );
  }
}

export default App;
