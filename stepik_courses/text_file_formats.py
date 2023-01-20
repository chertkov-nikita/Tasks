import pandas as pd


# 1. Вам необходимо узнать тип преступления, которое было зафиксировано максимальное
# число раз в 2015 году.
def first_task(year):
    data = pd.read_csv('Crimes.csv')
    data = data[['Date', 'Primary Type']]
    data['Date'] = pd.to_datetime(data['Date'])
    data = data[data['Date'].dt.to_period("Y") == year]
    return data['Primary Type'].value_counts().to_frame().idxmax()


def main():
    print(first_task('2015'))


if __name__ == '__main__':
    main()
