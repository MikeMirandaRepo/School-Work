import React from 'react';
import {IonCard, IonCardHeader, IonCardSubtitle, IonSkeletonText, IonCardTitle} from '@ionic/react'
import './LoadingCard.css';


const LoadingCard = () => (
    <IonCard>
        <IonCardHeader>
            <IonCardSubtitle>
                <IonSkeletonText animated className="loading-card__currency-name"/>
            </IonCardSubtitle>
            <IonCardTitle>
                <IonSkeletonText animated className="loading-card__currency-value"/>
            </IonCardTitle>
        </IonCardHeader>
    </IonCard>
);


export default LoadingCard;

