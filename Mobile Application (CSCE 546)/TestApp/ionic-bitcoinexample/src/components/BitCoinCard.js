import React from 'react';
import {IonCard, IonCardHeader, IonCardSubtitle, IonSkeletonText, IonCardTitle} from '@ionic/react'
import './BitCoinCard.css';


const BitCoinCard = (props) => (
    <IonCard>
        <IonCardHeader>
            <IonCardSubtitle>
                {props.data.code}
            </IonCardSubtitle>
            <IonCardTitle>
                {props.data.rate_float}
            </IonCardTitle>
        </IonCardHeader>
    </IonCard>
);

export default BitCoinCard;

