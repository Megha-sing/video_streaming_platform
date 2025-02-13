import React from "react";
import { Stack, Box } from "@mui/material";

import { ChannelCard,VideoCard } from './';

const Videos = ({ videos}) => {
  
  return (
    <Stack direction="row" 
    flexWrap="wrap" 
    justifyContent="space-evenly" 
    alignItems="start" 
    gap={2}>
      {Array.isArray(videos) && (videos)?.map((item, idx) => (
        <Box key={idx}>
          {item.id.videoId && <VideoCard video={item} /> }
          {item.id.channelId && <ChannelCard channelDetail={item} />}
        </Box>
      ))}
    </Stack>
  );

}
export default Videos;