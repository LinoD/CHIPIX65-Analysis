def read_calibration_data(filename):
	datafile_cal_TO2 = list(open(filename,"r"))

	col_1,col_2,col_3,col_4,col_5 = [],[],[],[],[]

	for col in datafile_cal_TO2:
		data = col.split()
		col_1.append(float(data[0]))
		col_2.append(float(data[1]))
		col_3.append(float(data[2]))
		col_4.append(float(data[3]))
		col_5.append(float(data[4]))
	return col_1,col_2,col_3,col_4,col_5
