import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonItemOption,
  IonAvatar,
  IonToolbar,
  IonList,
  IonItem,
  IonText,
  IonLabel,
  IonItemSliding,
  IonItemOptions,
  IonButton,
  IonIcon,
  IonBackButton,
  IonInput
} from "@ionic/react";
import React, { useState } from "react";
import { star } from "ionicons/icons";


const InputPage: React.FC = () => {
  const [input, setInput] = useState<string>("");

  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonButton slot="start">
            <IonBackButton />
          </IonButton>
          <IonTitle class="ion-text-center">Ionic Title in a Toolbar</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
        <IonInput
          value={input}
          onIonChange={(e: any) => setInput(e.target.value)}
        ></IonInput>
      </IonContent>
    </IonPage>
  );
};

export default InputPage;