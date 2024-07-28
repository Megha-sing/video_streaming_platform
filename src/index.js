import React from "react";
import ReactDOM from 'react-dom/client';
import App from "./App";
import './index.css';

//fetching from dom (html file --> index.html)
const root = ReactDOM.createRoot(document.getElementById('root')); 

root.render(<App/>);