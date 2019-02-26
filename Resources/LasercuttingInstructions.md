# LASERCUTTER INSTRUCTIONS

The lasercutter can "cut" a variety of materials (it actually burns through them) with very precise results. The machine can be easily damaged, so it's important you follow these instructions very carefully!

### SOME DESIGN CONSIDERATIONS  
* The lasercutter doesn't really "cut" through materials – it burns through them. For materials like plastics, that leaves a nice smooth edge. But for materials like wood or very thick paper, this means a visibly burnt edge. That burnt layer can be sanded off fairly easily.  
* The laser beam has a thickness (called *kerf*), which means parts don't come out the exact dimensions you specify. This will vary by material thickness too (thicker material = more noticeable kerf). For precise results, trial-and-error is usually best.  
* The laser is actually cone-shaped, meaning the edges it cuts aren't perfectly square to the top. This can cause issues when trying to have precise-fitting joints.  
* For clearance or tapped holes, see the hole guide in the Fab Lab or the test cut files in the `Resources` folder here.  

### MATERIALS  
The following materials are available in the Fab Lab and are approved for lasercutting. All other materials must be approved ahead of time by a VA&T faculty member!

* Acrylic plastic (1/8" thick cuts well, up to 1/4" ok)  
* Plywood (1/4" ok, must be very flat)  
* Paper (any kind)  
* Chipboard and matboard  

Possible but with help from a faculty member only:  
* Craft felt  
* Leather  
* Etching ceramic, stone, or metals

Definite no!  
* Mystery plastics not marked clearly as acrylic  
* Foams of any kind  
* PVC, which, when it melts, creates chlorine gas and can kill people!  
* Delrin, which off-gasses acetone which will melt the guts of the lasercutter  

### FILE PREP  
Your file must be in PDF format (or an image if you're just etching), which can be easily made in Adobe Illustrator or a similar tool. The laser software is very picky, so you need to follow these guidelines exactly:

1. File should be set up in RGB color mode  
2. All stroke weights must be 0.072pt (or 0.001in), thicker lines may be read as raster instead  
3. Cut: lines in red (`rgb(255,0,0)`)  
4. Vector etch: lines in blue (`rgb(0,0,255)`)  
5. Raster etch: images or fill in grayscale values, darker = deeper etch  

### LOADING THE FILE  
1. Move your file to the lasercutter PC in the Fab Lab with a thumb drive  
2. Double-click to open the PDF in Acrobat  
3. `File > Print...`  
4. Be sure `VLS` is the selected printer (should be by default)  
5. Hit `Print` (it won't start cutting, just send the info to the lasercutter software)  
6. Open the VLS software (it's icon is a little red diamond, in the applicaton tray at the bottom of the screen)  
7. Your design should appear!  

### PLACING YOUR DESIGN  
1. Turn on the lasercutter – it will take a few moments to find the origin    
2. Move your design to the desired location with the move command, typing in the location (**NOTE!** You must hit `enter` to make the design actually move!). It is generally best to keep your design at least 1/8" from the material's edge.

### SPECIFY MATERIAL  
1. Click the `Settings` button in the software  
2. Choose the proper material from the list – when in doubt, please ask!  
3. (Our acrylic is under `Plastic > Acrylic > Cast Acrylic > Cast Acrylic, Deep Engrave`)  
4. Type in the proper material size – acrylic sheets are `0.125"`, for other materials it's best to measure with a calipers  
5. Depending on your needs, you may want to adjust the engrave settings down – for a standard engrave, try `-40%` or so  
6. Hit `Apply` then `Ok`, then open the settings again to make sure your choices were saved  

### CUTTING  
1. Load your material onto the bed of the laser, making sure it's flat and straight  
2. (If it has a plastic film on it, the film must be removed but can be replaced with transfer paper used for the vinyl plotter.)  
3. Close the door of the lasercutter  
4. Turn on the fume extractor and the air compressor  
5. Verify everything is correct, then hit the `Play` button in the laser software  

**IMPORTANT!** You must stand by the lasercutter while any cut job is happening! Fire is a real danger and you must watch to be sure everything is ok. A small flare-up while cutting is normal, but if something catches fire, open the door to the lasercutter. It will shut down the cut job. If the fire continues, use the fire extinguisher near the door. **If any doubt: call 911.**

6. When done, let the fume extractor run for about a minute to clear all fumes  
7. Open the door and remove your part!

