

import sys

import ROOT 

from ROOT import TCanvas
from ROOT import TF1
from ROOT import TMath
from ROOT import TAxis

fileName = sys.argv[1]

f = open(fileName, "rb")


l = f.read()

nChar = len(l)

fileName_noisy = sys.argv[2]
noisy_pixels = []
count_noisy = 0

for line in open(fileName_noisy, "r").readlines():
	print line
	noisy_pixels.append(line.rstrip('\n')) 
	count_noisy += 1
#f_noisy = open(fileName_noisy,"r")
#l_noisy = f_noisy.read()
#lines =  f_noisy.read().splitlines()
#f_noisy.close()
#for line in lines:
#	print line


#noisy_pixels = []

#for h in range(0,len(l_noisy)):
#	noisy_pixels.append(l_noisy[h])
#	count_noisy += 1

print "Noisy pixels",noisy_pixels[0:count_noisy]

total_events = 0

event_counter = 0
packetNumber = 0
eventBytes = 0
kCode = 0
counter = 0
cluster = 0
number_of_hits = 0
cluster_signal = 0
cluster_pixels = 0
cluster_size = 0
cluster_size_1_2_array = []
pixel_1_2_array = []
pixel_1_2_counter = 0
ToT_1_2_array = []
ToT_6 = ToT_5 = ToT_4 = ToT_3 = ToT_2 = ToT_1 = 0

histo_pixel = ROOT.TH1F("histo_pixel","histo_pixel",4096,-0.5,4095.5)
histo_pixel_TO1 = ROOT.TH1F("histo_pixel_TO1","histo_pixel_TO1",1024,-0.5,1023.5)
histo_pixel_TO2 = ROOT.TH1F("histo_pixel_TO2","histo_pixel_TO2",1024,1023.5,2047.5)
histo_pixel_BGPV = ROOT.TH1F("histo_pixel_BGPV","histo_pixel_BGPV",2048,2047.5,4095.5)

histo_pixel_without_noisy_hits = ROOT.TH1F("histo_pixel_without_noisy_hits","histo_pixel_without_noisy_hits",4096,-0.5,4095.5)
histo_pixel_without_noisy_hits_TO1 = ROOT.TH1F("histo_pixel_without_noisy_hits_TO1","histo_pixel_without_noisy_hits_TO1",1024,-0.5,1023.5)
histo_pixel_without_noisy_hits_TO2 = ROOT.TH1F("histo_pixel_without_noisy_hits_TO2","histo_pixel_without_noisy_hits_TO2",1024,1023.5,2047.5)
histo_pixel_without_noisy_hits_BGPV = ROOT.TH1F("histo_pixel_without_noisy_hits_BGPV","histo_pixel_without_noisy_hits_BGPV",2048,2047.5,4095.5)

histo_pixel_signal = ROOT.TH1F("histo_pixel_signal","histo_pixel_signal",40,-0.5,39.5)
histo_pixel_signal_TO1 = ROOT.TH1F("histo_pixel_signal_TO1","histo_pixel_signal_TO1",40,-0.5,39.5)
histo_pixel_signal_TO2 = ROOT.TH1F("histo_pixel_signal_TO2","histo_pixel_signal_TO2",40,-0.5,39.5)
histo_pixel_signal_BGPV = ROOT.TH1F("histo_pixel_signal_BGPV","histo_pixel_signal_BGPV",40,-0.5,39.5)

histo_region_signal = ROOT.TH1F("histo_region_signal","histo_region_signal",100,-0.5,99.5)
histo_region_signal_TO1 = ROOT.TH1F("histo_region_signal_TO1","histo_region_signal_TO1",100,-0.5,99.5)
histo_region_signal_TO2 = ROOT.TH1F("histo_region_signal_TO2","histo_region_signal_TO2",100,-0.5,99.5)
histo_region_signal_BGPV = ROOT.TH1F("histo_region_signal_BGPV","histo_region_signal_BGPV",100,-0.5,99.5)

histo_cluster_signal = ROOT.TH1F("histo_cluster_signal","histo_cluster_signal",200,-0.5,199.5)
histo_cluster_signal_TO1 = ROOT.TH1F("histo_cluster_signal_TO1","histo_cluster_signal_TO1",200,-0.5,199.5)
histo_cluster_signal_TO2 = ROOT.TH1F("histo_cluster_signal_TO2","histo_cluster_signal_TO2",200,-0.5,199.5)
histo_cluster_signal_BGPV = ROOT.TH1F("histo_cluster_signal_BGPV","histo_cluster_signal_BGPV",200,-0.5,199.5)

histo_cluster_signal_size_1_2 = ROOT.TH1F("histo_cluster_signal_size_1_2","histo_cluster_signal_size_1_2",200,-0.5,199.5)
histo_cluster_signal_size_1_2_TO1 = ROOT.TH1F("histo_cluster_signal_size_1_2_TO1","histo_cluster_signal_size_1_2_TO1",200,-0.5,199.5)
histo_cluster_signal_size_1_2_TO2 = ROOT.TH1F("histo_cluster_signal_size_1_2_TO2","histo_cluster_signal_size_1_2_TO2",200,-0.5,199.5)
histo_cluster_signal_size_1_2_BGPV = ROOT.TH1F("histo_cluster_signal_size_1_2_BGPV","histo_cluster_signal_size_1_2_BGPV",200,-0.5,199.5)

histo_cluster_number_of_pixels = ROOT.TH1F("histo_cluster_number_of_pixels","histo_cluster_number_of_pixels",30,-0.5,29.5)
histo_cluster_number_of_pixels_TO1 = ROOT.TH1F("histo_cluster_number_of_pixels_TO1","histo_cluster_number_of_pixels_TO1",30,-0.5,29.5)
histo_cluster_number_of_pixels_TO2 = ROOT.TH1F("histo_cluster_number_of_pixels_TO2","histo_cluster_number_of_pixels_TO2",30,-0.5,29.5)
histo_cluster_number_of_pixels_BGPV = ROOT.TH1F("histo_cluster_number_of_pixels_BGPV","histo_cluster_number_of_pixels_BGPV",30,-0.5,29.5)

histo_cluster_signal_size_1_2_corrected = ROOT.TH1F("histo_cluster_signal_size_1_2_corrected","histo_cluster_signal_size_1_2_corrected",200,-0.5,199.5)
histo_cluster_signal_size_1_2_TO1_corrected = ROOT.TH1F("histo_cluster_signal_size_1_2_TO1_corrected","histo_cluster_signal_size_1_2_TO1_corrected",200,-0.5,199.5)
histo_cluster_signal_size_1_2_TO2_corrected = ROOT.TH1F("histo_cluster_signal_size_1_2_TO2_corrected","histo_cluster_signal_size_1_2_TO2_corrected",200,-0.5,199.5)
histo_cluster_signal_size_1_2_BGPV_corrected = ROOT.TH1F("histo_cluster_signal_size_1_2_BGPV_corrected","histo_cluster_signal_size_1_2_BGPV_corrected",200,-0.5,199.5)

histo_pixel_map = ROOT.TH2F("pixel_map","pixel_map",64,-0.5,63.5,64,-0.5,63.5)

histo_ToT_map = ROOT.TH2F("ToT map","ToT map",64,-0.5,63.5,64,-0.5,63.5)

for i in range(0, len(l))  :

	#print "%d \t %d" % (i, int(l[i].encode("hex"), 16))	
	#print "%d \t 0x%s" % (i, l[i].encode("hex"))		
	#h.SetBinContent(i+1, int(l[i].encode("hex"), 16))



        a = int(l[i].encode("hex"), 16)
	
	if (event_counter == 0 or event_counter == 23 + 15*cluster):
		if a == 220:
			event_counter = 0
			#print "%s \t %d" % ("Event number",total_events)
			total_events += 1
			event_counter = 0
			packetNumber = 0
			eventBytes = 0
			kCode = 0
			counter = 0
			bin = None
			bin_prev = None
			bin_64bit = None
			if(total_events > 1):
				noisy_hit = 0
				for g in range(0,count_noisy):
					if(pix_num[0] == int(noisy_pixels[g])):
						noisy_hit = 1
				if(noisy_hit == 0):
					histo_cluster_signal.Fill(cluster_signal)							
					histo_cluster_number_of_pixels.Fill(cluster_pixels)
					if(pix_num[0] >=0 and pix_num[0]<= 1023): 
							histo_cluster_signal_TO1.Fill(cluster_signal)
							histo_cluster_number_of_pixels_TO1.Fill(cluster_pixels)
					if(pix_num[0] >=1024 and pix_num[0]<= 2047):   
							histo_cluster_signal_TO2.Fill(cluster_signal)
							histo_cluster_number_of_pixels_TO2.Fill(cluster_pixels)
					if(pix_num[0] >=2048 and pix_num[0]<= 4095): 
							#print "%s \t %d \t %d" % ("Pixel e cluster",pix_num[0],cluster_signal)					
							histo_cluster_signal_BGPV.Fill(cluster_signal)
							histo_cluster_number_of_pixels_BGPV.Fill(cluster_pixels)
					if(cluster_size <= 2):
						cluster_size_1_2_array.append(cluster_size)
						for f in range(0, pixel_1_2_counter):
							pixel_1_2_array.append(pixel_1_2[f])
							ToT_1_2_array.append(ToT_1_2[f])
						histo_cluster_signal_size_1_2.Fill(cluster_signal)
						if(pix_num[0] >=0 and pix_num[0]<= 1023): 
							histo_cluster_signal_size_1_2_TO1.Fill(cluster_signal)
						if(pix_num[0] >=1024 and pix_num[0]<= 2047):   
							histo_cluster_signal_size_1_2_TO2.Fill(cluster_signal)
						if(pix_num[0] >=2048 and pix_num[0]<= 4095): 				
							histo_cluster_signal_size_1_2_BGPV.Fill(cluster_signal)
			cluster_signal = 0
			cluster_pixels = 0
			cluster = 0
			cluster_size = 0
			pixel_1_2_counter = 0
			ToT_1_2 = []
			pixel_1_2 = []
			ToT_6 = ToT_5 = ToT_4 = ToT_3 = ToT_2 = ToT_1 = 0
	
		else:
			counter = 8	
			kCode = 0		
			cluster += 1
			total_events += 1
			bin = None
			bin_prev = None
			bin_64bit = None
			ToT_6 = ToT_5 = ToT_4 = ToT_3 = ToT_2 = ToT_1 = 0
			#print "%s \t %s" % ("Bin_prev",bin_prev)  
	

	#print "%s \t %d" % ("Event counter",event_counter)
	#print "%s \t %d" % ("Cluster",cluster)
	#print "%s \t %d" % ("counter",counter)

	if (counter >= 2 and counter <=5):                                 #Packet number is in the header
		packetNumber+=256**(5-event_counter)*int(l[i].encode("hex"), 16)
		#print "%s \t %d" % ("Packet number",packetNumber)

	if (counter == 6 or counter == 7):				       #EventBytes is in the header
		eventBytes = 256**(7-event_counter)*int(l[i].encode("hex"), 16)
		#if event_counter == 7:
			#print "%s \t %d" % ("Event bytes",eventBytes)
			
	if (counter >= 8 and counter <=10):
		kCode+=int(l[i].encode("hex"), 16)
		#print "%s \t %d" % ("kCode",kCode)

	if (kCode == 123):
		if (counter != 13 and counter != 16 and counter != 19 and counter != 22):
			bin = format(int(l[i].encode("hex"), 16),'08b')
			if(counter == 11):
				bin_prev = bin
				#print "%s \t %s" % ("Bin",bin)  
				#print "%s \t %s" % ("Bin_prev",bin_prev)  
			if(counter > 11):
				bin_64bit = ''.join(map(str, [str(bin),str(bin_prev)]))
				#bin_64bit = ''.join(map(bin, [bin(bin),bin(bin_prev)]))
				#print "%s \t %s" % ("Bin",bin)  
				#print "%s \t %s" % ("Bin_64bit",bin_64bit)  
				bin_prev = bin_64bit
			if(counter == 21):
				macrocolumn = int(bin_64bit[0:4],2)
				#print "%s \t %s" % ("MacroColumn",macrocolumn) 
				timestamp = bin_64bit[4:14]
				#print "%s \t %s" % ("TimeStamp",timestamp) 
				macrorow = int(bin_64bit[14:18],2)
				#print "%s \t %s" % ("MacroRow",macrorow) 
				pixelmap = bin_64bit[18:34]
				#print "%s \t %s" % ("PixelMap",pixelmap) 
				pixel_colpito = []
				count_pix_colpito = 0
				for k in range(0,16):
					#print pixelmap[k]
					if(int(pixelmap[k],2) == 1):
						pixel_colpito.append(15-k)
						count_pix_colpito += 1
						number_of_hits +=1
						#print "%s \t %i" % ("Count_pix_colpito",count_pix_colpito)
				#print "Indirizzo pixel colpiti",pixel_colpito[0:count_pix_colpito+1]
				#print "%s \t %i" % ("Count_pix_colpito",count_pix_colpito)
				num_hit_pixels = []
				pix_num = []
				row = []
				column = []


				for m in range(0,count_pix_colpito):
					row_region = pixel_colpito[m]%4
					column_region = int(pixel_colpito[m]/4)
					pix_num.append(256*macrocolumn + 4*macrorow + 64*column_region + row_region)
					row.append(4*macrorow + row_region)
					column.append(4*macrocolumn + column_region)
					histo_pixel.Fill(pix_num[m])
					noisy_hit = 0
					cluster_size += 1
					for g in range(0,count_noisy):
						if(pix_num[0] == int(noisy_pixels[g])):
							noisy_hit = 1         
					if(noisy_hit == 0):
						histo_pixel_without_noisy_hits.Fill(pix_num[m])
						histo_pixel_map.Fill(column[m],row[m],1)
						#histo_cluster_signal.Fill(cluster_signal)
						if(pix_num[m] >=0 and pix_num[m]<= 1023):          
							histo_pixel_without_noisy_hits_TO1.Fill(pix_num[m])
	 					if(pix_num[m] >=1024 and pix_num[m]<= 2047):          
							histo_pixel_without_noisy_hits_TO2.Fill(pix_num[m])
						if(pix_num[m] >=2048 and pix_num[m]<= 4095):          
							histo_pixel_without_noisy_hits_BGPV.Fill(pix_num[m])
					if(pix_num[m] >=0 and pix_num[m]<= 1023):          
						histo_pixel_TO1.Fill(pix_num[m])
 					if(pix_num[m] >=1024 and pix_num[m]<= 2047):          
						histo_pixel_TO2.Fill(pix_num[m])
					if(pix_num[m] >=2048 and pix_num[m]<= 4095):          
						histo_pixel_BGPV.Fill(pix_num[m])	
					if(cluster_size <= 2):
						pixel_1_2.append(pix_num[m])
						pixel_1_2_counter += 1
						#print pixel_1_2[0:2], cluster_size, pixel_1_2_counter
				
				#print "Pixel colpiti",pix_num[0:count_pix_colpito+1]
				
				#print "%s \t %i \t %i" % ("ToT_6",ToT_6,count_pix_colpito) 
				if(count_pix_colpito >= 6):
					ToT_6 = int(bin_64bit[34:39],2) + 1	
					histo_pixel_signal.Fill(ToT_6)	
					histo_ToT_map.Fill(column[5],row[5],ToT_6)
					if(pix_num[5] >=0 and pix_num[5]<= 1023): 
						histo_pixel_signal_TO1.Fill(ToT_6)
					if(pix_num[5] >=1024 and pix_num[5]<= 2047):   
						histo_pixel_signal_TO2.Fill(ToT_6)
					if(pix_num[5] >=2048 and pix_num[5]<= 4095): 					
						histo_pixel_signal_BGPV.Fill(ToT_6)
					#print "%s \t %i \t %i" % ("ToT_6_saved",ToT_6_saved,count_pix_colpito) 
				#print "%s \t %s" % ("ToT_6",ToT_6) 
				if(count_pix_colpito >= 5):
					ToT_5 = int(bin_64bit[39:44],2) + 1
					histo_pixel_signal.Fill(ToT_5)
					histo_ToT_map.Fill(column[4],row[4],ToT_5)
					if(pix_num[4] >=0 and pix_num[4]<= 1023): 
						histo_pixel_signal_TO1.Fill(ToT_5)
					if(pix_num[4] >=1024 and pix_num[4]<= 2047):   
						histo_pixel_signal_TO2.Fill(ToT_5)
					if(pix_num[4] >=2048 and pix_num[4]<= 4095): 					
						histo_pixel_signal_BGPV.Fill(ToT_5)
				#print "%s \t %s" % ("ToT_5",ToT_5)
				if(count_pix_colpito >= 4):
					ToT_4 = int(bin_64bit[44:49],2) + 1
					histo_pixel_signal.Fill(ToT_4)
					histo_ToT_map.Fill(column[3],row[3],ToT_4)
					if(pix_num[3] >=0 and pix_num[3]<= 1023): 
						histo_pixel_signal_TO1.Fill(ToT_4)
					if(pix_num[3] >=1024 and pix_num[3]<= 2047):   
						histo_pixel_signal_TO2.Fill(ToT_4)
					if(pix_num[3] >=2048 and pix_num[3]<= 4095): 					
						histo_pixel_signal_BGPV.Fill(ToT_4)	
				#print "%s \t %s" % ("ToT_4",ToT_4)
				if(count_pix_colpito >= 3):
					ToT_3 = int(bin_64bit[49:54],2) + 1
					histo_pixel_signal.Fill(ToT_3)
					histo_ToT_map.Fill(column[2],row[2],ToT_3)
					if(pix_num[2] >=0 and pix_num[2]<= 1023): 
						histo_pixel_signal_TO1.Fill(ToT_3)
					if(pix_num[2] >=1024 and pix_num[2]<= 2047):   
						histo_pixel_signal_TO2.Fill(ToT_3)
					if(pix_num[2]>=2048 and pix_num[2]<= 4095): 					
						histo_pixel_signal_BGPV.Fill(ToT_3)
				#print "%s \t %s" % ("ToT_3",ToT_3)
				#print "%s \t %i \t %i" % ("ToT_2",ToT_2,count_pix_colpito) 
				if(count_pix_colpito >= 2):
					ToT_2 = int(bin_64bit[54:59],2) + 1
					#print "%s \t %i \t %i" % ("Pixel_2",pix_num[1],count_pix_colpito)
					histo_pixel_signal.Fill(ToT_2)
					histo_ToT_map.Fill(column[1],row[1],ToT_2)
					if(pix_num[1] >=0 and pix_num[1]<= 1023): 
						histo_pixel_signal_TO1.Fill(ToT_2)
					if(pix_num[1] >=1024 and pix_num[1]<= 2047):   
						histo_pixel_signal_TO2.Fill(ToT_2)
					if(pix_num[1] >=2048 and pix_num[1]<= 4095): 					
						histo_pixel_signal_BGPV.Fill(ToT_2)
				if(cluster_size <= 2 and count_pix_colpito == 2):
					ToT_1_2.append(ToT_2)				
				#print "%s \t %i \t %i" % ("ToT_2_saved",ToT_2_saved,count_pix_colpito) 
				#print "%s \t %s" % ("ToT_2",ToT_2)
				if(count_pix_colpito >= 1):	
					ToT_1 = int(bin_64bit[59:64],2)	+ 1
					#print "%s \t %i \t %i" % ("Pixel_1",pix_num[0],count_pix_colpito)					
					for g in range(0,count_noisy):
						if(pix_num[0] == int(noisy_pixels[g])):
							noisy_hit = 1         
					if(noisy_hit == 0):
						histo_pixel_signal.Fill(ToT_1)	
						histo_ToT_map.Fill(column[0],row[0],ToT_1)
						if(pix_num[0] >=0 and pix_num[0]<= 1023): 
							histo_pixel_signal_TO1.Fill(ToT_1)
						if(pix_num[0] >=1024 and pix_num[0]<= 2047):   
							histo_pixel_signal_TO2.Fill(ToT_1)
						if(pix_num[0] >=2048 and pix_num[0]<= 4095): 					
							histo_pixel_signal_BGPV.Fill(ToT_1)
				if(cluster_size <= 2 and count_pix_colpito <= 2):
						ToT_1_2.append(ToT_1)	
						#print ToT_1_2[0:2], cluster_size	
				#print "%s \t %s" % ("ToT_1",ToT_1)
				region_signal = ToT_6+ToT_5+ToT_4+ToT_3+ToT_2+ToT_1
				cluster_signal += region_signal
				cluster_pixels += count_pix_colpito
				#print "%s \t %i \t %i \t %i \t %i" % ("Cluster pixels",packetNumber,event_counter,cluster_pixels,count_pix_colpito)
				#print "%s \t %s" % ("Cluster charge",region_signal)
				
				for g in range(0,count_noisy):
						if(pix_num[0] == int(noisy_pixels[g])):
							noisy_hit = 1         
				if(noisy_hit == 0):
					histo_region_signal.Fill(region_signal)
					if(pix_num[0] >=0 and pix_num[0]<= 1023): 
							histo_region_signal_TO1.Fill(region_signal)
					if(pix_num[0] >=1024 and pix_num[0]<= 2047):   
							histo_region_signal_TO2.Fill(region_signal)
					if(pix_num[0] >=2048 and pix_num[0]<= 4095): 					
							histo_region_signal_BGPV.Fill(region_signal)					
				del pixel_colpito
	
	event_counter += 1
	counter += 1

print len(pixel_1_2_array)
print len(ToT_1_2_array)
print len(cluster_size_1_2_array)

dead_pixels = []
count_dead_pixels = 0

print "%s \t %d" % ("Number of packets",packetNumber)
print "%s \t %d" % ("Number of events",total_events)
print "%s \t %d" % ("Number of hit pixels",number_of_hits)

for n in range(1,4096):
	bin_content = histo_pixel.GetBinContent(n)
	if (bin_content == 0):
		dead_pixels.append(n-1)
		count_dead_pixels += 1 

print "Dead pixels",dead_pixels[0:count_dead_pixels+1]

count_cluster_size = 0
count_single_cluster = 0
Total_ToT = 0
near_dead_pixel = 0
count_clusters_corrected = 0
count_clusters_deleted = 0


for n in range(0,len(pixel_1_2_array)):
	#print n, cluster_size_1_2_array[count_cluster_size], count_cluster_size, near_dead_pixel, count_single_cluster
	near_dead_pixel = 0
	if(cluster_size_1_2_array[count_cluster_size] == 1):
		for g in range (0,count_dead_pixels):
			if(pixel_1_2_array[n] == dead_pixels[g] or pixel_1_2_array[n] == (dead_pixels[g] + 1) or pixel_1_2_array[n] == (dead_pixels[g] -1) or pixel_1_2_array[n] == (dead_pixels[g] -63) or pixel_1_2_array[n] == (dead_pixels[g] + 63) or pixel_1_2_array[n] == (dead_pixels[g] -63) or pixel_1_2_array[n] == (dead_pixels[g] + 64) or (pixel_1_2_array[n] == dead_pixels[g] - 64)):
				near_dead_pixel = 1
		if(near_dead_pixel == 0):
			if(ToT_1_2_array[n] < 32):  #Eliminates the ToT overflows
				if(pixel_1_2_array[n] >=0 and pixel_1_2_array[n]<= 1023):
					if(pixel_1_2_array[n] > 63 and pixel_1_2_array[n]%64 > 0): 
						histo_cluster_signal_size_1_2_corrected.Fill(ToT_1_2_array[n])
						histo_cluster_signal_size_1_2_TO1_corrected.Fill(ToT_1_2_array[n])
						count_clusters_corrected += 1
				if(pixel_1_2_array[n] >=1024 and pixel_1_2_array[n]<= 2047):   
					#if(ToT_1_2_array[n] % 2 == 1):
						#print pixel_1_2_array[n], ToT_1_2_array[n]
					histo_cluster_signal_size_1_2_corrected.Fill(ToT_1_2_array[n])
					histo_cluster_signal_size_1_2_TO2_corrected.Fill(ToT_1_2_array[n])
					count_clusters_corrected += 1
				if(pixel_1_2_array[n] >=2048 and pixel_1_2_array[n]<= 4095): 	
					if(pixel_1_2_array[n] < 4028): 			
						histo_cluster_signal_size_1_2_corrected.Fill(ToT_1_2_array[n])	
						histo_cluster_signal_size_1_2_BGPV_corrected.Fill(ToT_1_2_array[n])
						count_clusters_corrected += 1
			count_cluster_size+=1
			#print "done_1"
		else:	
			count_cluster_size+=1
			count_clusters_deleted+=1
			#print "done_1_bis"
	else:
		for g in range (0,count_dead_pixels):
			if(pixel_1_2_array[n] == dead_pixels[g] or pixel_1_2_array[n] == (dead_pixels[g] + 1) or pixel_1_2_array[n] == (dead_pixels[g] -1) or pixel_1_2_array[n] == (dead_pixels[g] -63) or pixel_1_2_array[n] == (dead_pixels[g] + 63) or pixel_1_2_array[n] == (dead_pixels[g] -63) or pixel_1_2_array[n] == (dead_pixels[g] + 64) or (pixel_1_2_array[n] == dead_pixels[g] - 64)):
				near_dead_pixel = 1
		if(near_dead_pixel == 0):
			if(count_single_cluster == 0):
				ToT_A = ToT_1_2_array[n]
				#print ToT_A
				count_single_cluster += 1
				#print "done_2"
			elif(count_single_cluster == 1):
				ToT_B = ToT_1_2_array[n]	
				#print "done_2b"
				Total_ToT = ToT_A + ToT_B
				if(ToT_A < 32 and ToT_B < 32): #Eliminates the ToT overflows
					if((pixel_1_2_array[n] >=0 and pixel_1_2_array[n]<= 1023) and (pixel_1_2_array[n-1] >=0 and pixel_1_2_array[n-1]<= 1023)):    #Elimina anche il caso di due pixel in due FE diversi
						if((pixel_1_2_array[n] > 63 and pixel_1_2_array[n-1]> 63) and (pixel_1_2_array[n]%64 > 0 and pixel_1_2_array[n-1]%64 > 0) and ((pixel_1_2_array[n]-1)%64 > 0 and (pixel_1_2_array[n-1]-1)%64 > 0)): #Elimina i pixel ai bordi
							histo_cluster_signal_size_1_2_corrected.Fill(Total_ToT)					
							histo_cluster_signal_size_1_2_TO1_corrected.Fill(Total_ToT)
							count_clusters_corrected += 1
					if((pixel_1_2_array[n] >=1024 and pixel_1_2_array[n]<= 2047)  and (pixel_1_2_array[n-1] >=1024 and pixel_1_2_array[n-1]<= 2047)):   
						if ((pixel_1_2_array[n]%64 > 0 and pixel_1_2_array[n-1]%64 > 0) and ((pixel_1_2_array[n]-1)%64 > 0 and (pixel_1_2_array[n-1]-1)%64 > 0)): #Elimina i pixel ai bordi
							histo_cluster_signal_size_1_2_corrected.Fill(Total_ToT)
							histo_cluster_signal_size_1_2_TO2_corrected.Fill(Total_ToT)
							count_clusters_corrected += 1
					if((pixel_1_2_array[n] >=2048 and pixel_1_2_array[n]<= 4095) and (pixel_1_2_array[n-1] >=2048 and pixel_1_2_array[n-1]<= 4095)): 
						if((pixel_1_2_array[n] < 4028 and pixel_1_2_array[n-1]< 4028) and (pixel_1_2_array[n]%64 > 0 and pixel_1_2_array[n-1]%64 > 0) and ((pixel_1_2_array[n]-1)%64 > 0 and (pixel_1_2_array[n-1]-1)%64 > 0)):		#Elimina i pixel ai bordi			
							histo_cluster_signal_size_1_2_corrected.Fill(Total_ToT)					
							histo_cluster_signal_size_1_2_BGPV_corrected.Fill(Total_ToT)
							count_clusters_corrected += 1				
				count_single_cluster = 0
				count_cluster_size+=1
		else:
			if(count_single_cluster == 0):
				count_single_cluster += 1
			elif(count_single_cluster == 1):
				count_cluster_size+=1
				count_clusters_deleted+=1
				#print "done_2d"
				count_single_cluster = 0

print "count_clusters_1_2_maintained =", count_clusters_corrected
#print "count_clusters_1_2_deleted =", count_clusters_deleted

#cvs1 = TCanvas("Global histograms","Global histograms")
#cvs1.Divide(2,2)
#cvs1.cd(1)
#histo_pixel.Draw()
#cvs1.cd(2)
#histo_pixel_signal.Draw()
#cvs1.cd(3)
#histo_region_signal.Draw()
#cvs1.cd(4)
#histo_cluster_signal.Draw()

cvs2 = TCanvas("Hits per pixel","Hits per pixel")
cvs2.Divide(2,2)
cvs2.cd(1)
histo_pixel.Draw()
cvs2.cd(2)
histo_pixel_TO1.Draw()
cvs2.cd(3)
histo_pixel_TO2.Draw()
cvs2.cd(4)
histo_pixel_BGPV.Draw()

cvs3 = TCanvas("Signal histograms","Signal histograms")
cvs3.Divide(2,2)
cvs3.cd(1)
histo_pixel_signal.Draw()
cvs3.cd(2)
histo_pixel_signal_TO1.Draw()
cvs3.cd(3)
histo_pixel_signal_TO2.Draw()
cvs3.cd(4)
histo_pixel_signal_BGPV.Draw()

cvs4 = TCanvas("Region signal histograms","Region signal histograms")
cvs4.Divide(2,2)
cvs4.cd(1)
histo_region_signal.Draw()
cvs4.cd(2)
histo_region_signal_TO1.Draw()
cvs4.cd(3)
histo_region_signal_TO2.Draw()
cvs4.cd(4)
histo_region_signal_BGPV.Draw()

cvs5 = TCanvas("Cluster signal histograms","Cluster signal histograms")
cvs5.Divide(2,2)
cvs5.cd(1)
histo_cluster_signal.Draw()
cvs5.cd(2)
histo_cluster_signal_TO1.Draw()
cvs5.cd(3)
histo_cluster_signal_TO2.Draw()
cvs5.cd(4)
histo_cluster_signal_BGPV.Draw()

cvs6 = TCanvas("Number of pixels in the cluster","Number of pixels in the cluster")
cvs6.Divide(2,2)
cvs6.cd(1)
histo_cluster_number_of_pixels.Draw()
cvs6.cd(2)
histo_cluster_number_of_pixels_TO1.Draw()
cvs6.cd(3)
histo_cluster_number_of_pixels_TO2.Draw()
cvs6.cd(4)
histo_cluster_number_of_pixels_BGPV.Draw()


cvs7 = TCanvas("Hits per pixel without noisy channels","Hits per pixel without noisy channels")
cvs7.Divide(2,2)
cvs7.cd(1)
histo_pixel_without_noisy_hits.Draw()
cvs7.cd(2)
histo_pixel_without_noisy_hits_TO1.Draw()
cvs7.cd(3)
histo_pixel_without_noisy_hits_TO2.Draw()
cvs7.cd(4)
histo_pixel_without_noisy_hits_BGPV.Draw()

f1 = ROOT.TF1("f1","[0]*TMath::Landau(x,[1],[2])",5,40)
f1.SetParameters(7600.,7.,1.64)


cvs8 = TCanvas("Cluster signal size 1 or 2 histograms","Cluster signal size 1 or 2 histograms")
cvs8.Divide(2,2)
cvs8.cd(1)
histo_cluster_signal_size_1_2.Draw()
cvs8.cd(2)
histo_cluster_signal_size_1_2_TO1.Fit("f1","R")
ROOT.gStyle.SetOptFit(1)
histo_cluster_signal_size_1_2_TO1.Draw()
cvs8.cd(3)
histo_cluster_signal_size_1_2_TO2.Fit("f1","R")
ROOT.gStyle.SetOptFit(1)
histo_cluster_signal_size_1_2_TO2.Draw()
cvs8.cd(4)
histo_cluster_signal_size_1_2_BGPV.Fit("f1","R")
ROOT.gStyle.SetOptFit(1)
histo_cluster_signal_size_1_2_BGPV.Draw()

cvs11 = TCanvas("Cluster_1_2_corrected","Cluster_1_2_corrected")
cvs11.Divide(2,2)
cvs11.cd(1)
histo_cluster_signal_size_1_2_corrected.Draw()
cvs11.cd(2)
histo_cluster_signal_size_1_2_TO1_corrected.Draw()
cvs11.cd(3)
histo_cluster_signal_size_1_2_TO2_corrected.Draw()
cvs11.cd(4)
histo_cluster_signal_size_1_2_BGPV_corrected.Draw()
ROOT.gStyle.SetOptStat(1)

cvs9 = TCanvas("Pixel map","Pixel map")
histo_pixel_map.Draw("COLZ")
histo_pixel_map.GetXaxis().SetTitle("column")
histo_pixel_map.GetYaxis().SetTitle("row")
ROOT.gStyle.SetOptStat(0)

cvs10 = TCanvas("ToT map","ToT map")
histo_ToT_map.Draw("COLZ")
histo_ToT_map.GetXaxis().SetTitle("column")
histo_ToT_map.GetYaxis().SetTitle("row")
ROOT.gStyle.SetOptStat(0)



raw_input()
