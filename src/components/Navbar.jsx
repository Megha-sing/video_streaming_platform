import React from 'react'
import { Stack,Box, Button } from '@mui/material';
import { Link } from 'react-router-dom';
import logo from './logo.png';
import SearchBar from './SearchBar';
import NotificationsIcon from '@mui/icons-material/Notifications';
import VideoCallIcon from '@mui/icons-material/VideoCall';
import AccountCircleIcon from '@mui/icons-material/AccountCircle';

const Navbar = () => (
  <Stack direction="row" 
  alignItems="center" 
  p={2} 
  sx={{ position:  "sticky", background: '#000', top: 0, justifyContent: "space-between" }}>
    <Link to="/" style={{ display: "flex", alignItems: "center" }}>
      <img src={logo} alt="logo" height={45} />
    </Link>
    <SearchBar/>

    <Box sx={{ justifyContent: 'center'}} >
      <Button><NotificationsIcon sx={{ color: 'white'}} /></Button>
      <Button><VideoCallIcon sx={{ color: 'white'}} /></Button>
      <Button><AccountCircleIcon sx={{ color: 'white'}} /></Button>
</Box>


  </Stack>
);

export default Navbar;